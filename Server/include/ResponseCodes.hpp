/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** ResponseCodes
*/

#ifndef RESPONSECODES_HPP_
#define RESPONSECODES_HPP_

/* According to RFC 2616 */

#define SP " "
#define CRLF "\r\n"

#define CONTINUE "100 Continue"
#define SWITCHING "101 Switching Protocols"

#define OK "200 OK"
#define CREATED "201 Created"
#define ACCEPTED "202 Accepted"
#define NAUTH_INFO "203 Non-Authoritative Information"
#define NO_CONTENT "204 No Content"
#define RESET_CONTENT "205 Reset Content"
#define PARTIAL_CONTENT "206 Partial Content"

#define MULT_CHOICES "300 Multiple Choices"
#define MOVED "301 Moved Permanently"
#define FOUND "302 Found"
#define OTHER "303 See Other"
#define NOT_MODIFIED "304 Not Modified"
#define PROXY "305 Use Proxy"
#define UNUSED "306 (Unused)"
#define TEMP_REDIRECT "307 Temporary Redirect"

#define BAD_REQ "400 Bad Request"
#define UNAUTH "401 Unauthorized"
#define PAY_REQUIRED "402 Payment Required"
#define FORBIDDEN "403 Forbidden"
#define NOT_FOUND "404 Not Found"
#define METHOD_NOT_ALLOWED "405 Method Not Allowed"
#define NOT_ACCEPTABLE "406 Not Acceptable"
#define PROXY_AUTH_REQUIRED "407 Proxy Authentication Required"
#define TIMEOUT "408 Request Timeout"
#define CONFLICT "409 Conflict"
#define GONE "410 Gone"
#define LENGHT_REQUIRED "411 Length Required"
#define PRECOND_FAILED "412 Precondition Failed"
#define REQUEST_ENTITY_TOO_LARGE "413 Request Entity Too Large"
#define REQUEST_URI_TOO_LONG "414 Request-URI Too Long"
#define UNSUPPORTED_MEDIA "415 Unsupported Media Type"
#define REQ_RANGE_NOT_SATISFIABLE "416 Requested Range Not Satisfiable"
#define EXPECTATION_FAILED "417 Expectation Failed"

#define INTERNAL_SERV_ERROR "500 Internal Server Error"
#define NOT_IMPLEMENTED "501 Not Implemented"
#define BAD_GATEWAY "502 Bad Gateway"
#define SERVICE_UNAVAILABLE "503 Service Unavailable"
#define GATEWAY_TIMEOUT "504 Gateway Timeout"
#define VERSION_NOT_SUPPORTED "505 HTTP Version Not Supported"

#endif /* !RESPONSECODES_HPP_ */