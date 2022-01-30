/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Connexion
*/

#ifndef CONNEXIONHTTPS_HPP_
#define CONNEXIONHTTPS_HPP_

#include "../interfaces/IConnexion.hpp"
#include "ClientHTTPS.hpp"

class ConnexionHTTPS: public IConnexion {
    public:
        ConnexionHTTPS(boost::asio::io_context &io_context, unsigned short port, RequestHandler &handler);
        ~ConnexionHTTPS();
        void init() override;
        void accept() override;

    protected:
    private:
        boost::asio::io_context &_io_context;
        boost::asio::ip::tcp::acceptor _acceptor;
        boost::asio::ssl::context _context;
        RequestHandler &_handler;
        std::vector<std::shared_ptr<ClientHTTPS>> _saveClient;
};

#endif /* !CONNEXIONHTTPS_HPP_ */