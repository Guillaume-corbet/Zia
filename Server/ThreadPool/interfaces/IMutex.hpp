/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
#define IMUTEX_HPP_

template <typename T>
class IMutex {
    public:
        virtual ~IMutex() = default;
        virtual T &getLocker() = 0;
        virtual void Lock() = 0;
        virtual void Unlock() = 0;
        virtual bool isLock() = 0;

    protected:
        T _locker;
};

#endif /* !IMUTEX_HPP_ */