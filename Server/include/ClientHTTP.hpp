/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Client
*/

#ifndef CLIENTHTTP_HPP_
#define CLIENTHTTP_HPP_

#include "RequestHandler.hpp"

class ClientHTTP: public IClient {
    public:
        ClientHTTP(boost::asio::ip::tcp::tcp::socket socket, RequestHandler &handler);
        ~ClientHTTP();
        void start();
        void read();
        void write(std::string buf);

    protected:
    private:
        boost::asio::ip::tcp::tcp::socket _socket;
        std::string _bufferString;
        char _buffer[2048];
        RequestHandler &_handler;
};

#endif /* !CLIENTHTTP_HPP_ */