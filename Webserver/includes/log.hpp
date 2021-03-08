#ifndef LOG_HPP
# define LOG_HPP

#include "request.hpp"

struct Log
{
    /**
    * Custom Logs struct.
    * LOG format: "%h %u %t \"%r\" 
 
        %h            – Remote IP.
        %u            – Remote user if the request was authenticated.
        %t            – Time the request was received.
        %r            – First line of request.
        %{REFERER}    – The contents of Referer: header line in the request sent to the server. 
        %{USER_AGENT} - The contents of User-Agent: header line in the request sent to the server. 

    */

    std::map<std::string, std::string> headers;
    std::string ip;
    std::string auth;
    std::string timestamp;
    std::string startLine;
    int status;
    std::string referer;
    std::string userAgent;

    Log(Request *req, std::string const &clientIp, int statusCode);
    ~Log();

    void    printLog(void);
};

#endif