/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Connexion
*/

#include "../include/ConnexionHTTPS.hpp"

ConnexionHTTPS::ConnexionHTTPS(boost::asio::io_context &io_context, unsigned short port, RequestHandler &handler): _io_context(io_context), _acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), _context(boost::asio::ssl::context::sslv23), _handler(handler)
{
    _isAlive = true;
}

ConnexionHTTPS::~ConnexionHTTPS()
{
    _isAlive = false;
    if (_acceptor.is_open()) {
        _acceptor.cancel();
        _acceptor.close();
    }
}

void ConnexionHTTPS::init()
{
    _context.set_options(boost::asio::ssl::context::default_workarounds | boost::asio::ssl::context::no_sslv2 | boost::asio::ssl::context::single_dh_use);
    _context.set_default_verify_paths();
    _context.use_certificate_chain_file("localhost.pem");
    _context.use_private_key_file("localhost.pem", boost::asio::ssl::context::pem);
    
    _context.use_tmp_dh_file("dhparam.pem");
}

void ConnexionHTTPS::accept()
{
    _acceptor.async_accept([this](const boost::system::error_code& error, boost::asio::ip::tcp::socket socket) {
        if (!error && _isAlive) {
            _saveClient.push_back(std::make_shared<ClientHTTPS>(std::move(socket), _context, _handler));
            _saveClient.at(_saveClient.size() - 1)->start();
        }
        if (_isAlive) {
            accept();
        }
    });
}