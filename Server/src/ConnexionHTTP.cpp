/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Connexion
*/

#include "../include/ConnexionHTTP.hpp"

ConnexionHTTP::ConnexionHTTP(boost::asio::io_context &io_context, unsigned short port, RequestHandler &handler): _io_context(io_context), _acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), _handler(handler)
{
    _isAlive = true;
}

ConnexionHTTP::~ConnexionHTTP()
{
    _isAlive = false;
    if (_acceptor.is_open()) {
        _acceptor.cancel();
        _acceptor.close();
    }
}

void ConnexionHTTP::init()
{
}

void ConnexionHTTP::accept()
{
    _acceptor.async_accept([this](const boost::system::error_code& error, boost::asio::ip::tcp::tcp::socket socket) {
        if (!error && _isAlive) {
            _saveClient.push_back(std::make_shared<ClientHTTP>(std::move(socket), _handler));
            _saveClient.at(_saveClient.size() - 1)->start();
        }
        if (_isAlive) {
            accept();
        }
    });
}