/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/

#include "Config/include/ConfigHandler.hpp"
#include "Server/modules/PhpModule/PhpModule.hpp"
#include "Server/include/Server.hpp"

Server *s;
ConfigHandler *conf;
boost::asio::io_context io_context;

void loadConfig()
{
    if (s) {
        s->~Server();
        io_context.reset();
    }
    if (conf->getConfig().getServerType() == Config::ServType::HTTPS) {
        std::cout << "Starting Server with " << RED << "HTTPS" << WHITE << " communication protocol..." << std::endl;
        std::cout << "Host: " << BLUE << conf->getConfig().getHost() << WHITE << ", Port: " << BLUE << conf->getConfig().getPortHttps() << WHITE << "." << std::endl;
    } else {
        std::cout << "Starting Server with " << RED << "HTTP" << WHITE << " communication protocol..." << std::endl;
        std::cout << "Host: " << BLUE << conf->getConfig().getHost() << WHITE << ", Port: " << BLUE << conf->getConfig().getPortHttp() << WHITE << "." << std::endl;
    }
    s = new Server(io_context, conf->getConfig());
    try {
        io_context.run();
    }
    catch(...) {
        std::cerr << "error in io_context" << std::endl;
    }
}

void signalHandler(int signum)
{
    std::cout << "Server configuration modified (" << signum << ")." << std::endl;
    if (signum == SIGUSR1) {
        io_context.stop();
        // sleep(1);
    } else if (signum == SIGUSR2) {
        s->loadModules(conf->getConfig());
    }
}

int main(int ac, char **av)
{
    std::signal(SIGUSR1, signalHandler);
    std::signal(SIGUSR2, signalHandler);
    conf = new ConfigHandler();

    while (true) {
        loadConfig();
    }
    return (0);
}