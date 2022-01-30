/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include "../include/Request.hpp"
#include "../include/Response.hpp"

#define RED std::string("\x1B[31m")
#define WHITE std::string("\033[0m")
#define YELLOW std::string("\033[33m")
#define GREEN std::string("\x1B[32m")
#define BLUE std::string("\033[34m")

class IModule {
    public:
        enum IType {OPTION, GET, HEAD, POST, PUT, TRACE, CONNECT, NONE};
        enum IName {PHP, VOID};
        typedef IModule::IName name;
        typedef IModule::IType type;
        virtual name getName() const {return (_name);};
        virtual void setType() {_type.push_back(type::NONE);};
        virtual std::vector<type> getType() const {return _type;};
        virtual ~IModule() = default;
        virtual std::shared_ptr<Response> run(std::shared_ptr<Request> req) {return (std::make_shared<Response>());};

    protected:
        name _name;
        std::vector<type> _type;
};

#endif /* !IMODULE_HPP_ */