# include "log.hpp"

# define OPEN_QUOTE " \""
# define CLOSING_QUOTE "\" "
# define OPEN_BRACKET "["
# define CLOSING_BRACKET "]"
# define HYPHEN " - "

Log::Log(Request *req, std::string const &clientIp, int statusCode)
{
    headers = req->getHeadersMap();
    ip = clientIp;
    timestamp = utils::dateHeader();
    startLine = req->getStartLine();
    if (startLine.size() > 100)
        startLine = startLine.substr(0, 100);
    status = statusCode;
    if (utils::hasHeader("authorization:", headers))
    {
        auth = headers["authorization:"];
        if (auth.find("Basic") != std::string::npos)
        {
            std::string creds(auth, 6, (auth.size() - 6));
            std::vector<std::string> credsVector = utils::split(utils::base64Decode(creds), ':');
            auth = credsVector[0];
        }
    }
    if (utils::hasHeader("referer:", headers))
        referer = headers["referer:"];
    if (referer.size() > 100)
        referer = referer.substr(0, 100);
    if (utils::hasHeader("user-agent:", headers))
        userAgent = headers["user-agent:"];
    if (userAgent.size() > 100)
        userAgent = userAgent.substr(0, 100);

    printLog();
}

Log::~Log()
{
}

void    Log::printLog(void)
{
    std::cout   << std::endl
                << ip
                << HYPHEN << auth << HYPHEN
                << OPEN_BRACKET << timestamp << CLOSING_BRACKET 
                << OPEN_QUOTE << startLine << CLOSING_QUOTE
                << status 
                << OPEN_QUOTE << referer << CLOSING_QUOTE
                << OPEN_QUOTE << userAgent << CLOSING_QUOTE
                << std::endl;
}