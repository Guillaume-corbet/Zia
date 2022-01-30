/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Response
*/

#ifndef RESPONSE_HPP_
#define RESPONSE_HPP_

#include <string>
#include <vector>
#include <map>
#include "ResponseCodes.hpp"

class Response {
    public:
        Response() {
            this->respLine = OK;
            this->body = "";
        };
        ~Response() {};

        std::string respLine;
        std::string body;

        std::vector<std::string> header;

    protected:
    private:
};

#endif /* !RESPONSE_HPP_ */