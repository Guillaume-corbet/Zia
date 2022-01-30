/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** IClient
*/

#ifndef ICLIENT_HPP_
#define ICLIENT_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

class IClient: public std::enable_shared_from_this<IClient> {
    public:
        virtual ~IClient() = default;
        virtual void start() = 0;
        virtual void read() = 0;
        virtual void write(std::string buffer) = 0;

    protected:
};

#endif /* !ICLIENT_HPP_ */