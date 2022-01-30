/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Client
*/

#ifndef CLIENTHTTPS_HPP_
#define CLIENTHTTPS_HPP_

#include "RequestHandler.hpp"

class ClientHTTPS: public IClient {
    public:
        ClientHTTPS(boost::asio::ip::tcp::socket socket, boost::asio::ssl::context &context, RequestHandler &handler);
        ~ClientHTTPS();
        void start();
        void read();
        void write(std::string buf);

    protected:
    private:
        boost::asio::ssl::stream<boost::asio::ip::tcp::socket> _socket;
        std::string _bufferString;
        char _buffer[2048];
        RequestHandler &_handler;
};

#endif /* !CLIENTHTTPS_HPP_ */