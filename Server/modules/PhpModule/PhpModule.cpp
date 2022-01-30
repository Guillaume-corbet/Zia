/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** PhpModule
*/

#include "PhpModule.hpp"

PhpModule::PhpModule()
{
    _name = name::PHP;
    setType();
}

PhpModule::~PhpModule()
{
}

void PhpModule::setType()
{
    _type.push_back(type::GET);
}

std::string PhpModule::getRealFile(std::string req)
{
    std::string file;

    if (req == "/") {
        file = "index.php";
    } else if (!req.empty()) {
        file = req.substr(1, req.size());
    } else {
        file = "";
    }
    return (file);
}

void PhpModule::setHeader(std::shared_ptr<Response> res, std::shared_ptr<Request> req)
{
    res->header.push_back("Age: 0");
    res->header.push_back("Access-Control-Allow-Origin: *");
    res->header.push_back("Server: boost/1.71.0");
    res->header.push_back("Vary: Accept-Encoding");
    if (res->respLine.at(0) == '2') {
        res->header.push_back("Content-Length: " + std::to_string(res->body.size()));
        res->header.push_back("Content-Type: text/html");
    }
}

std::shared_ptr<Response> PhpModule::run(std::shared_ptr<Request> req)
{
    std::shared_ptr<Response> response = std::make_shared<Response>();
    FILE *fp;
    char path[512];
    std::string pathFile = getRealFile(req->URI);
    std::string file;

    if (pathFile.empty()) {
        response->respLine = std::string(NOT_FOUND) + std::string(CRLF);
        setHeader(response, req);
        return (response);
    }
    file = "php -f ";
    file = file + PATHFILE + pathFile;
    std::ifstream f((PATHFILE + pathFile).c_str());
    if (!f.good()) {
        response->respLine = std::string(NOT_FOUND) + std::string(CRLF);
        setHeader(response, req);
        return (response);
    }
    #ifdef __linux__
    fp = popen(file.c_str(), "r");
    while (fgets(path, 512, fp) != NULL) {
        response->body = response->body + std::string(path);
    }
    pclose(fp);
    #elif _WIN32
    fp = _popen(file.c_str(), "r");
    while (fgets(path, 512, fp) != NULL) {
        response->body = response->body + std::string(path);
    }
    _pclose(fp);
    #endif
    setHeader(response, req);
    response->respLine = std::string(OK) + std::string(CRLF);
    return (response);
}