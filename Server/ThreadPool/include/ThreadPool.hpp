/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include "Threads.hpp"

class ThreadPool {
    public:
        ThreadPool(size_t size, RequestParser &parser, std::vector<IModule *>& modules);
        ~ThreadPool();
        void notify(const std::pair<std::string, IClient *> req);

    protected:
    private:
        Mutex *_mut;
        CondVar *_var;
        RequestList *_list;
        std::vector<Threads *> _pool;
};

#endif /* !THREADPOOL_HPP_ */