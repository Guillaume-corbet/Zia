/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** ConfigHandler
*/

#ifndef CONFIGHANDLER_HPP_
#define CONFIGHANDLER_HPP_

#include <iostream>
#include <fstream>
// #include <filesystem>
// #include "boost/filesystem.hpp"
#include <nlohmann/json.hpp>
#include "Config.hpp"
#include <thread>
#include <csignal>
#include <algorithm>
#ifdef __linux__ 
    #define PATH_CONFIG "configServerZia.json"
#elif _WIN32
    #define PATH_CONFIG "../../../configServerZia.json"
    #define SIGUSR1 10
    #define SIGUSR2 12
#else
    #define PATH_CONFIG "configServerZia.json"
#endif

class ConfigHandler {
    public:
        ConfigHandler();
        ~ConfigHandler();
        void updateConfig();
        Config &getConfig();
        bool test_unitaire_goodpath();
        bool test_unitaire_defaultconfig();
        bool test_unitaire_defaultmodule();
    protected:
    private:
        void defaultModule();
        void fillServerConfig(const nlohmann::json &j);
        std::ifstream exists(std::string filepath);
        void fillDefaultServerConfig();
        nlohmann::json readConfigFile();
        void addModule(const nlohmann::json &j, int i);
        void create();
        void run();
        bool changeVector(std::vector<Module> allModule);
        Config serverConfig;
        std::thread _thread;
};

#endif /* !CONFIG_HPP_ */
