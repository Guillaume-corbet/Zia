/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** ICondVar
*/

#ifndef ICONDVAR_HPP_
#define ICONDVAR_HPP_

template <class T>
class ICondVar {
    public:
        virtual ~ICondVar() = default;
        virtual void wait(T &elm) = 0;
        virtual void notify_all() = 0;
        virtual void notify_one() = 0;

    protected:
};

#endif /* !ICONDVAR_HPP_ */