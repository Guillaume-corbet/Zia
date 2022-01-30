/*
** EPITECH PROJECT, 2021
** B-YEP-500-MAR-5-1-zia-samuel.parayre
** File description:
** PhpModule
*/

#ifndef PHPMODULE_HPP_
#define PHPMODULE_HPP_

#include "../../interfaces/IModule.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

#ifdef __linux__
    #include <unistd.h>
    #include <cstring>
    #include <cstdlib>
    #define PATHFILE ""
#elif _WIN32
    #define PATHFILE "../../../"

#endif


class PhpModule : public IModule {
    public:
        PhpModule();
        ~PhpModule();
        name getName() const override {return (_name);};
        void setType() override;
        std::vector<type> getType() const override {return (_type);};
        std::shared_ptr<Response> run(std::shared_ptr<Request> req) override;
        void setHeader(std::shared_ptr<Response> res, std::shared_ptr<Request> req);
        std::string getRealFile(std::string req);

    protected:
    private:
};

/*extern "C"
{
    IModule *entryPoint()
    {
        return (new PhpModule());
    }
}*/

#endif /* !PHPMODULE_HPP_ */