/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Threads
*/

#ifndef THREADS_HPP_
#define THREADS_HPP_

#include <iostream>
#include <thread>
#include "Mutex.hpp"
#include "CondVar.hpp"
#include "../../interfaces/IModule.hpp"
#include "../../include/RequestList.hpp"
#include "../../include/RequestParser.hpp"

class Threads {
    public:
        Threads(Mutex &locker, RequestList &work, CondVar &condVar, RequestParser &parser, std::vector<IModule *> &listModule);
        ~Threads();
        bool isTypeValid(std::vector<IModule::type> vectType, std::string type);
        void create();
        void run();
        void respond(std::shared_ptr<Response> resp, IClient *cli, std::string httpVersion);
        std::shared_ptr<Response> createResponse(std::shared_ptr<Request> req);
        std::shared_ptr<Response> createError(std::string msg);
        void join();

    protected:
    private:
        std::thread _thread;
        Mutex &_lock;
        CondVar &_condVar;
        RequestList &_work;
        RequestParser &_parser;
        std::vector<IModule *> &_listModule;
        static const std::map<IModule::type, std::string> _methods;
};

#endif /* !THREADS_HPP_ */