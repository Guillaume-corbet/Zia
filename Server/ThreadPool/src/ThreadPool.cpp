/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** ThreadPool
*/

#include "../include/ThreadPool.hpp"

ThreadPool::ThreadPool(size_t size, RequestParser &parser, std::vector<IModule *> &modules)
{
    std::cout << "Creating a " << YELLOW << size << "-threads" << WHITE << " ThreadPool..." << std::endl;
    _mut = new Mutex();
    _var = new CondVar();
    _list = new RequestList();
    for (size_t i = 0; i < size; i++) {
        _pool.push_back(new Threads(*_mut, *_list, *_var, parser, modules));
    }
}

ThreadPool::~ThreadPool()
{
    _mut->~Mutex();
    _list->~RequestList();
    if (!_pool.empty()) {
        _pool.erase(_pool.begin(), _pool.end());
    }
}

void ThreadPool::notify(const std::pair<std::string, IClient *> req)
{
    if (_list->size() >= _pool.size()) {
        std::string tmp = std::string("HTTP/1.1") + SP + std::string(SERVICE_UNAVAILABLE);

        tmp += std::string("Age: 0") + CRLF;
        tmp += std::string("Access-Control-Allow-Origin: *") + CRLF;
        tmp += std::string("Server: boost/1.71.0") + CRLF;
        tmp += std::string("Vary: Accept-Encoding") + CRLF;
        req.second->write(tmp);
    } else {
        _list->push(req);
        _var->notify_one();
    }
}
