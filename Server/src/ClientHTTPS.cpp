/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Client
*/

#include "../include/ClientHTTPS.hpp"

ClientHTTPS::ClientHTTPS(boost::asio::ip::tcp::socket socket, boost::asio::ssl::context& context, RequestHandler &handler): _socket(std::move(socket), context), _handler(handler)
{
}

ClientHTTPS::~ClientHTTPS()
{
}

void ClientHTTPS::start()
{
    auto self(shared_from_this());

    _socket.async_handshake(boost::asio::ssl::stream_base::server, [this, self](const boost::system::error_code &error) {
        if (!error) {
            read();
        }
        else {
            std::cerr << "Error in handleshake !! " << error.message() << std::endl;
        }
    });
}

void ClientHTTPS::read()
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

void ClientHTTPS::write(std::string buffer)
{
    auto self(shared_from_this());

    boost::asio::async_write(_socket, boost::asio::buffer(buffer, buffer.size()), [this, self](const boost::system::error_code &error, std::size_t /*length*/) {
        if (error)
            std::cerr << "Error in write !! " << error.message() << std::endl;
    });
}