/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** RequestHandler
*/

#include "../include/RequestHandler.hpp"

RequestHandler::RequestHandler(int size)
{
    _isAlive = true;
    _list = new RequestList();
    _parser = new RequestParser();
    _modules = new std::vector<IModule *>;
    _pool = new ThreadPool(size, *_parser, *_modules);
    launchThread();
}

RequestHandler::~RequestHandler()
{
    _isAlive = false;
    _list->~RequestList();
    _parser->~RequestParser();
    if (!_modules->empty()) {
        _modules->erase(_modules->begin(), _modules->end());
    }
    _pool->~ThreadPool();
    if (_thread->joinable())
        _thread->join();
}

bool RequestHandler::loadModule(IModule *newModule)
{
    bool ret = true;

    for (size_t i = 0; i < _modules->size(); i++) {
        if (_modules->at(i)->getName() == newModule->getName())
            ret = false;
    }
    if (ret) {
        try {
            _modules->push_back(newModule);
        } catch (...) {
            ret = false;
        }
    }
    return (ret);
}

bool RequestHandler::eraseModule(IModule::name name)
{
    for (size_t i = 0; i < _modules->size(); i++) {
        if (_modules->at(i)->getName() == name)
            _modules->erase(_modules->begin() + i);
            return (true);
    }
    return (false);
}

void RequestHandler::eraseAllModules()
{
    for (size_t i = 0; i < _modules->size(); i++) {
        _modules->erase(_modules->begin());
    }
}

IModule *RequestHandler::getModule(IModule::name name)
{
    for (size_t i = 0; i < _modules->size(); i++) {
        if (_modules->at(i)->getName() == name)
            return (_modules->at(i));
    }
    return (NULL);
}

void RequestHandler::pushNewRequest(const std::string &req, IClient *ptr)
{
    _list->push(req, ptr);
}

void RequestHandler::launchThread()
{
    _thread = new std::thread(&RequestHandler::run, this);
}

void RequestHandler::run()
{
    while (_isAlive) {
        if (!_list->isEmpty()) {
            handleRequest();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

void RequestHandler::handleRequest()
{
    for (size_t i = 0; i < _list->size(); i++) {
        _pool->notify(_list->get());
        _list->pop();
    }
}