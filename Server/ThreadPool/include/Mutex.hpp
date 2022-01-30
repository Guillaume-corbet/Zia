/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <mutex>
#include "../interfaces/IMutex.hpp"

class Mutex: public IMutex<std::mutex> {
    public:
        Mutex();
        ~Mutex();
        std::mutex &getLocker();
        void Lock();
        void Unlock();
        bool isLock();

    protected:
    private:
};

#endif /* !MUTEX_HPP_ */