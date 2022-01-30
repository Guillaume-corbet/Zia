/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <functional>
//#include "DLLoader.hpp"
#include "../modules/PhpModule/PhpModule.hpp"
#include "ConnexionHTTPS.hpp"
#include "ConnexionHTTP.hpp"
#include "RequestHandler.hpp"
#include "../../Config/include/ConfigHandler.hpp"

class Server {
    public:
        Server(boost::asio::io_context& io_context, Config &conf);
        ~Server();
        void loadModules(Config &conf);

    protected:
    private:
        RequestHandler _handler;
        std::shared_ptr<IConnexion> _connexionModule;
};

#endif /* !SERVER_HPP_ */