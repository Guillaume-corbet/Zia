/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** ConfigHandler
*/

#include "../include/ConfigHandler.hpp"

using json = nlohmann::json;

ConfigHandler::ConfigHandler()
{
    this->serverConfig = Config();
    fillDefaultServerConfig();
    this->updateConfig();
    this->create();
}

ConfigHandler::~ConfigHandler()
{
}

void ConfigHandler::create()
{
    _thread = std::thread(&ConfigHandler::run, this);
}

void ConfigHandler::run()
{
    std::string lastServerType;
    int portHttp;
    int portHttps;
    int max_request;
    std::vector<Module> allModule;
    while (true) {
        lastServerType = this->serverConfig._servType;
        portHttp = this->serverConfig._portHttp;
        portHttps = this->serverConfig._portHttps;
        max_request = this->serverConfig._max_request;
        std::copy(this->serverConfig._listModule.begin(), this->serverConfig._listModule.end(), back_inserter(allModule));
        this->updateConfig();
        if (lastServerType != this->serverConfig._servType)
            std::raise(SIGUSR1);
        else if (portHttp != this->serverConfig._portHttp && this->serverConfig._servType == "http")
            std::raise(SIGUSR1);
        else if (portHttps != this->serverConfig._portHttps && this->serverConfig._servType == "https")
            std::raise(SIGUSR1);
        else if (max_request != this->serverConfig._max_request)
            std::raise(SIGUSR1);
        else if (changeVector(allModule)) {
            std::raise(SIGUSR2);
        }
        allModule.clear();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool ConfigHandler::changeVector(std::vector<Module> allModule)
{
    if (allModule.size() != this->serverConfig._listModule.size()) {
        return (true);
    }
    for (size_t i = 0; i < allModule.size(); i++) {
        if (allModule.at(i).getName() != serverConfig._listModule.at(i).getName()) {
            return (true);
        } else if (allModule.at(i).getNameDLL() != serverConfig._listModule.at(i).getNameDLL()) {
            return (true);
        }
    }
    return (false);
}

std::ifstream ConfigHandler::exists(std::string filepath)
{
    std::ifstream pathStream(filepath.c_str());
    return pathStream;
}

json ConfigHandler::readConfigFile()
{
    std::ifstream i;

    try {
        if ((i = exists(PATH_CONFIG)).good() == true) {
            json j;
            try {
                i >> j;
            } catch (...) {
                return (NULL);
            }
            return (j);
        } else if ((i = exists("configServerZia.json")).good() == true) {
            json j;
            i >> j;
            return (j);
        } else {
            return (NULL);
        }
    }
    catch (...) {
        return (NULL);
    }
} 

void ConfigHandler::fillServerConfig(const json &j)
{
    try {
        j.at("host").get_to(this->serverConfig._host);
    } catch(nlohmann::detail::out_of_range) {
        this->serverConfig._host = "127.0.0.1";
    }
    try {
        j.at("portHTTP").get_to(this->serverConfig._portHttp);
    } catch (nlohmann::detail::out_of_range) {
        this->serverConfig._portHttp = 8080;
    }
    try {
        j.at("portHTTPS").get_to(this->serverConfig._portHttps);
    } catch (nlohmann::detail::out_of_range) {
        this->serverConfig._portHttps = 8081;
    }
    try {
        j.at("max_request").get_to(this->serverConfig._max_request);
    } catch (nlohmann::detail::out_of_range) {
        this->serverConfig._max_request = 20;
    }
    try {
        j.at("serverType").get_to(this->serverConfig._servType);
    } catch (nlohmann::detail::out_of_range) {
        this->serverConfig._servType = "http";
    }
    if (this->serverConfig._servType != "http" && this->serverConfig._servType != "https" && this->serverConfig._servType != "HTTP" && this->serverConfig._servType != "HTTPS")
        this->serverConfig._servType = "http";
    for (int i = 0; i < j.at("modules").size(); i++) {
        try {
            Module module(j.at("modules")[i].at("name"), j.at("modules")[i].at("active"), j.at("modules")[i].at("nameDLL"));
            if (module.isActive())
                this->serverConfig.addToListModule(module);
        } catch (nlohmann::detail::out_of_range) {
            break;
        }
    }
}

void ConfigHandler::fillDefaultServerConfig()
{
    this->serverConfig._host = "127.0.0.1";
    this->serverConfig._portHttp = 8080;
    this->serverConfig._portHttps = 8081;
    this->serverConfig._max_request = 20;
    this->serverConfig._servType = "http";
    defaultModule();
}

void ConfigHandler::addModule(const json& j, int i)
{
    try {
        Module module(j.at("modules")[i].at("name"), j.at("modules")[i].at("active"), j.at("modules")[i].at("nameDLL"));
        this->serverConfig.addToListModule(module);
    } catch (nlohmann::detail::out_of_range) {
        std::cout << "no more module" << std::endl;
    }
}

void ConfigHandler::defaultModule()
{
    Module modulePhp("php", true, "php.dll");
    this->serverConfig.addToListModule(modulePhp);
}

void ConfigHandler::updateConfig()
{
    json file = readConfigFile();

    this->serverConfig.cleanListModule();

    if (file == NULL) {
        fillDefaultServerConfig();
    } else {
        fillServerConfig(file);
    }
}

Config &ConfigHandler::getConfig()
{
    return (this->serverConfig);
}

bool ConfigHandler::test_unitaire_goodpath()
{
    if (readConfigFile() == NULL) {
        return (false);
    } else {
        return (true);
    }
}

bool ConfigHandler::test_unitaire_defaultconfig()
{
    fillDefaultServerConfig();

    if (this->serverConfig._host == "127.0.0.1" && this->serverConfig._portHttp == 8080 && this->serverConfig._portHttps == 8081 && this->serverConfig._max_request == 20) {
        return (true);
    } else {
        return (false);
    }
}

bool ConfigHandler::test_unitaire_defaultmodule()
{
    defaultModule();

    std::string firstModName = this->serverConfig.getListModule().at(1).getName();
    std::string firstModNameDLL = this->serverConfig.getListModule().at(1).getNameDLL();
    bool firstModActive = this->serverConfig.getListModule().at(1).isActive();

    std::string secondModName = this->serverConfig.getListModule().at(2).getName();
    std::string secondModNameDLL = this->serverConfig.getListModule().at(2).getNameDLL();
    bool secondModActive = this->serverConfig.getListModule().at(2).isActive();

    if (firstModName == "security" && firstModNameDLL == "security.dll" && firstModActive == true &&
        secondModName == "php" && secondModNameDLL == "php.dll" && secondModActive == true) {
            return (true);
    } else {
        return (false);
    }
}