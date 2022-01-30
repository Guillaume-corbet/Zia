/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Config
*/

#include "../include/Config.hpp"

Config::Config()
{
}

Config::~Config()
{
}

std::string Config::getHost() const
{
    return (this->_host);
}

int Config::getPortHttp() const
{
    return (this->_portHttp);
}

int Config::getPortHttps() const
{
    return (this->_portHttps);
}

Config::ServType Config::getServerType() const
{
    if (_servType == "HTTPS" || _servType == "https")
        return (ServType::HTTPS);
    return (ServType::HTTP);
}

int Config::getMaxRequest() const
{
    return (this->_max_request);
}

std::vector<Module> Config::getListModule() const
{
    return (this->_listModule);
}

void Config::addToListModule(Module module)
{
    this->_listModule.push_back(module);
}

void Config::cleanListModule()
{
    this->_listModule.clear();
}