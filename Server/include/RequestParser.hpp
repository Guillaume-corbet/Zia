/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** RequestParser
*/

#ifndef REQUESTPARSER_HPP_
#define REQUESTPARSER_HPP_

#include <iostream>
#include <cstring>
#include "Request.hpp"
#include "ResponseCodes.hpp"

class RequestParser {
    public:
        RequestParser();
        ~RequestParser();
        bool findInVect(const std::vector<std::string> &vect, const std::string &str);
        std::vector<std::string> parseAtSep(std::string &str, const std::string sep);
        void parseReqLine(std::string &req, std::shared_ptr<Request> cur);
        std::shared_ptr<Request> parseReq(std::string &req);

    protected:
    private:
        static const std::vector<std::string> _methods;
        static const std::vector<std::string> _httpVersions;
        static const std::vector<std::string> _headers;
};

#endif /* !REQUESTPARSER_HPP_ */