/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Client
*/

#include "../include/ClientHTTP.hpp"

ClientHTTP::ClientHTTP(boost::asio::ip::tcp::tcp::socket socket, RequestHandler &handler): _socket(std::move(socket)), _handler(handler)
{
}

ClientHTTP::~ClientHTTP()
{
}

void ClientHTTP::start()
{
    read();
}

void ClientHTTP::read()
{
    auto self(shared_from_this());

    _socket.async_read_some(boost::asio::buffer(_buffer), [this, self](const boost::system::error_code &error, std::size_t length) {
        _bufferString.clear();
        if (!error && std::strlen(_buffer)) {
            _bufferString = std::string(_buffer);
            _handler.pushNewRequest(_bufferString, this);
        } else {
            std::cerr << "Error in read !! " << error.message() << std::endl;
        }
    });
}

void ClientHTTP::write(std::string buffer)
{
    auto self(shared_from_this());

    boost::asio::async_write(_socket, boost::asio::buffer(buffer, buffer.size()), [this, self](const boost::system::error_code &error, std::size_t /*length*/) {
        if (error)
            std::cerr << "Error in write !! " << error.message() << std::endl;
    });
}