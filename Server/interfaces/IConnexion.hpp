/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** IConnexion
*/

#ifndef ICONNEXION_HPP_
#define ICONNEXION_HPP_

class IConnexion {
    public:
        virtual ~IConnexion() = default;
        virtual void init() = 0;
        virtual void accept() = 0;

    protected:
        bool _isAlive;
};

#endif /* !ICONNEXION_HPP_ */