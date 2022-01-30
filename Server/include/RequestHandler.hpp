/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** RequestHandler
*/

#ifndef REQUESTHANDLER_HPP_
#define REQUESTHANDLER_HPP_

#include <thread>
#include "../interfaces/IModule.hpp"
#include "RequestList.hpp"
#include "RequestParser.hpp"
#include "../ThreadPool/include/ThreadPool.hpp"

class RequestHandler {
    public:
        RequestHandler(int size);
        ~RequestHandler();
        bool loadModule(IModule *newModule);
        bool eraseModule(IModule::name name);
        void eraseAllModules();
        IModule *getModule(IModule::name name);
        void pushNewRequest(const std::string &req, IClient *ptr);
        void launchThread();

    protected:
        void run();
        void handleRequest();

    private:
        bool _isAlive;
        RequestList *_list;
        RequestParser *_parser;
        std::vector<IModule *> *_modules;
        ThreadPool *_pool;
        std::thread *_thread;
};

#endif /* !REQUESTHANDLER_HPP_ */