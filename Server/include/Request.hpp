/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** Request
*/

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include <string>
#include <vector>
#include <map>
#include <memory>

class Request {
    public:
        Request() {
            this->err = "";
            this->requestType = "";
            this->body = "";
            this->URI = "";
            this->httpVersion = "";
        };
        ~Request() {};

        std::string err;

        std::string requestType;
        std::string URI;
        std::string httpVersion;
        std::vector<std::string> header;
        std::string body;

    protected:
    private:
};

#endif /* !REQUEST_HPP_ */