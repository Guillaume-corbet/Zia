/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** Config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <iostream>
#include <vector>
#include "Module.hpp"

class Config {
    public:
        enum ServType {HTTP, HTTPS};
        Config();
        ~Config();
        std::string getHost() const;
        int getPortHttp() const;
        int getPortHttps() const;
        ServType getServerType() const;
        int getMaxRequest() const;
        std::vector<Module> getListModule() const;
        void addToListModule(Module module);
        void cleanListModule();

        std::string _host;
        int _portHttp;
        int _portHttps;
        std::string _servType;
        int _max_request;
        std::vector<Module> _listModule;
};

#endif /* !CONFIG_HPP_ */