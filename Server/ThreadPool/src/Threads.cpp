/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Threads
*/

#include "../include/Threads.hpp"

Threads::Threads(Mutex &locker, RequestList &work, CondVar &condVar, RequestParser &parser, std::vector<IModule *> &listModule): _lock(locker), _condVar(condVar), _work(work), _parser(parser), _listModule(listModule)
{
    create();
}

Threads::~Threads()
{
    if (_thread.joinable())
		_thread.join();
}

const std::map<IModule::type, std::string> Threads::_methods = {
    {IModule::type::OPTION, "OPTION"},
    {IModule::type::GET, "GET"},
    {IModule::type::HEAD, "HEAD"},
    {IModule::type::POST, "POST"},
    {IModule::type::PUT, "PUT"},
    {IModule::type::TRACE, "TRACE"},
    {IModule::type::CONNECT, "CONNECT"},
    {IModule::type::NONE, "NONE"}
};

bool Threads::isTypeValid(std::vector<IModule::type> vectType, std::string type)
{
    for (size_t i = 0; i < vectType.size(); i++) {
        if (_methods.at(vectType.at(i)) == type)
            return (true);
    } return (false);
};

void Threads::create()
{
    _thread = std::thread(&Threads::run, this);
}

void Threads::run()
{
    std::pair<std::string, IClient *> cur;
    std::shared_ptr<Request> req;
    std::shared_ptr<Response> resp;

    while (true) {
        _condVar.wait(_lock);
        if (!_work.isEmpty()) {
            _lock.Lock();
            cur = _work.get();
            req = _parser.parseReq(cur.first);
            // std::cout << "REQ: \n" << cur.first << "\n###" << std::endl;
            if (!req->err.empty()) {
                resp = createError(req->err);
            } else {
                resp = createResponse(req);
            }
            respond(resp, cur.second, req->httpVersion);
            _work.pop();
            _lock.Unlock();
            req->~Request();
            resp->~Response();
        }
    }
}

void Threads::respond(std::shared_ptr<Response> resp, IClient *cli, std::string httpVersion)
{
    std::string tmp;

    tmp = "HTTP/" + httpVersion + SP + std::string(resp->respLine);

    for (size_t i = 0; i < resp->header.size(); i++) {
        tmp += resp->header.at(i) + CRLF;
    }
    if (!resp->body.empty())
        tmp += CRLF + resp->body;
    else
        tmp += CRLF;
    // std::cout << "RESPONSE: " << tmp << std::endl;
    cli->write(tmp);
    tmp.clear();
}

std::shared_ptr<Response> Threads::createResponse(std::shared_ptr<Request> req)
{
    std::shared_ptr<Response> resp;
    for (size_t i = 0; i < _listModule.size(); i++) {
        if (isTypeValid(_listModule.at(i)->getType(), req->requestType)) {
            resp = _listModule.at(i)->run(req);
            break;
        }
    }
    if (resp->respLine.empty()) {
        resp->~Response();
        return (createError(METHOD_NOT_ALLOWED));
    }
    return (resp);
}

std::shared_ptr<Response> Threads::createError(std::string msg)
{
    std::shared_ptr<Response> resp = std::make_shared<Response>();
    resp->respLine = msg;

    return (resp);
}

void Threads::join()
{
    if (_thread.joinable()) {
        _thread.join();
    }
}