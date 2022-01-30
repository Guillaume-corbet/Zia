/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Server
*/

#include "../include/Server.hpp"

Server::Server(boost::asio::io_context& io_context, Config &conf): _handler(conf.getMaxRequest())
{
    /*DLLoader<IModule> load;
    void *handler;
    
    for (size_t i = 0; i < conf.getListModule().size(); i++) {
        if (_handler.loadModule(load.getInstance(conf.getListModule().at(i).getNameDLL().c_str(), &handler))) {
            std::cout << "Module " << conf.getListModule().at(i).getName() << " loaded." << std::endl;
        } else {
            std::cout << "Module " << conf.getListModule().at(i).getName() << " failed to load." << std::endl;
        }
    }*/
    loadModules(conf);
    if (conf.getServerType() == Config::ServType::HTTPS) {
        _connexionModule = std::make_shared<ConnexionHTTPS>(io_context, conf.getPortHttps(), _handler);
    } else {
        _connexionModule = std::make_shared<ConnexionHTTP>(io_context, conf.getPortHttp(), _handler);
    }
    _connexionModule->init();
    _connexionModule->accept();
}

Server::~Server()
{
}

void Server::loadModules(Config &conf)
{
    _handler.eraseAllModules();
    for (size_t i = 0; i < conf.getListModule().size(); i++) {
        std::cout << "Loading " << GREEN << conf.getListModule().at(i).getName() << WHITE << " Module..." << std::endl;
        if (conf.getListModule().at(i).getName() == "php") {
            _handler.loadModule(new PhpModule());
        }
    }
}