/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** RequestParser
*/

#include "../include/RequestParser.hpp"

RequestParser::RequestParser()
{
}

RequestParser::~RequestParser()
{
}

const std::vector<std::string> RequestParser::_methods = {
    "OPTION",
    "GET",
    "HEAD",
    "POST",
    "PUT",
    "TRACE",
    "CONNECT"
};

const std::vector<std::string> RequestParser::_httpVersions = {
    "HTTP/1.0",
    "HTTP/1.1"
};

const std::vector<std::string> RequestParser::_headers = {
    "Accept",
	"Accept-Charset",
	"Accept-Encoding",
	"Accept-Language",
	"Authorization",
	"Expect",
	"From",
	"Host",
	"If-Match",
	"If-Modified-Since",
	"If-None-Match",
	"If-Range",
	"If-Unmodified-Since",
	"Max-Forwards",
	"Proxy-Authorization",
	"Range",
	"Referer",
	"TE",
	"User-Agent"
};

bool RequestParser::findInVect(const std::vector<std::string> &vect, const std::string &str)
{
    for (std::string ite : vect) {
        if (ite == str) {
            return (true);
        }
    }
    return (false);
}

std::vector<std::string> RequestParser::parseAtSep(std::string &str, const std::string sep)
{
    std::vector<std::string> res;
    size_t prev = 0;

    for (size_t i = 0; i < str.size() - sep.size(); i++) {
        if (str.substr(i, sep.size()) == sep) {
            res.push_back(str.substr(prev, i - prev));
            prev = i + sep.size();
        }
    }
    res.push_back(str.substr(prev, str.size() - prev));
    return (res);
}

void RequestParser::parseReqLine(std::string &req, std::shared_ptr<Request> cur)
{
    std::vector<std::string> reqLine = parseAtSep(req, SP);

    if (reqLine.size() != 3) {
        cur->err = EXPECTATION_FAILED;
    } else if (!findInVect(_methods, reqLine.at(0))) {
        cur->err = NOT_IMPLEMENTED;
        cur->httpVersion = reqLine.at(2).substr(5);
    } else if (!findInVect(_httpVersions, reqLine.at(2))) {
        cur->err = VERSION_NOT_SUPPORTED;
        cur->httpVersion = reqLine.at(2).substr(5);
    } else {
        cur->requestType = reqLine.at(0);
        cur->URI = reqLine.at(1);
        cur->httpVersion = reqLine.at(2).substr(5);
    }
}

std::shared_ptr<Request> RequestParser::parseReq(std::string &req)
{
    std::shared_ptr<Request> newReq = std::make_shared<Request>();
    std::vector<std::string> parsedReq = parseAtSep(req, CRLF);
    size_t i = 1;

    for (size_t j = 0; j < parsedReq.size(); j++) {
        if (parsedReq.at(j).empty())
            continue;
        if (parsedReq.at(j).at(parsedReq.at(j).size() - 1) == '\n') {
            parsedReq.at(j) = parsedReq.at(j).substr(0, parsedReq.at(j).size() - 1);
        }
        if (parsedReq.at(j).at(parsedReq.at(j).size() - 1) == '\r') {
            parsedReq.at(j) = parsedReq.at(j).substr(0, parsedReq.at(j).size() - 1);
        }
    }
    parseReqLine(parsedReq.at(0), newReq);
    while (i < parsedReq.size()) {
        if (parsedReq.at(i).empty())
            break;
        newReq->header.push_back(parsedReq.at(i));
        i++;
    }
    i++;
    while (i < parsedReq.size()) {
        newReq->body += parsedReq.at(i) + CRLF;
        i++;
    }
    return (newReq);
}