/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Connexion
*/

#ifndef CONNEXIONHTTP_HPP_
#define CONNEXIONHTTP_HPP_

#include "../interfaces/IConnexion.hpp"
#include "ClientHTTP.hpp"

class ConnexionHTTP: public IConnexion {
    public:
        ConnexionHTTP(boost::asio::io_context &io_context, unsigned short port, RequestHandler &handler);
        ~ConnexionHTTP();
        void init() override;
        void accept() override;

    protected:
    private:
        boost::asio::io_context &_io_context;
        std::vector<std::shared_ptr<ClientHTTP>> _saveClient;
        boost::asio::ip::tcp::acceptor _acceptor;
        RequestHandler &_handler;
};

#endif /* !CONNEXIONHTTP_HPP_ */