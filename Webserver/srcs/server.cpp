# include "server.hpp"

HTTPServer::HTTPServer()
{
    _implementedMethods.push_back("GET");
    _implementedMethods.push_back("HEAD");
    _implementedMethods.push_back("POST");
    _implementedMethods.push_back("PUT");

    _statusCodeMap[200] = "OK";
	_statusCodeMap[201] = "Created";
	_statusCodeMap[202] = "Accepted";
	_statusCodeMap[203] = "Non-Authoritative Information";
	_statusCodeMap[204] = "No Content";
	_statusCodeMap[205] = "Reset Content";

	_statusCodeMap[300] = "Multiple Choices";
	_statusCodeMap[301] = "Moved Permanently";
	_statusCodeMap[302] = "Found";
	_statusCodeMap[303] = "See Other";
	_statusCodeMap[305] = "Use Proxy";
	_statusCodeMap[306] = "(Unused)";
	_statusCodeMap[307] = "Temporary Redirect";

	_statusCodeMap[400] = "Bad Request";
	_statusCodeMap[401] = "Unauthorized";
	_statusCodeMap[402] = "Payment Required";
	_statusCodeMap[403] = "Forbidden";
	_statusCodeMap[404] = "Not Found";
	_statusCodeMap[405] = "Method Not Allowed";
	_statusCodeMap[406] = "Not Acceptable";
	_statusCodeMap[408] = "Request Timeout";
	_statusCodeMap[409] = "Conflict";
	_statusCodeMap[410] = "Gone";
	_statusCodeMap[411] = "Length Required";
	_statusCodeMap[413] = "Payload Too Large";
	_statusCodeMap[414] = "URI Too Long";
	_statusCodeMap[415] = "Unsupported Media Type";
	_statusCodeMap[417] = "Expectation Failed";
	_statusCodeMap[426] = "Upgrade Required";

	_statusCodeMap[500] = "Internal Server Error";
	_statusCodeMap[501] = "Not Implemented";
	_statusCodeMap[502] = "Bad Gateway";
	_statusCodeMap[503] = "Service Unavailable";
	_statusCodeMap[504] = "Gateway Timeout";
	_statusCodeMap[505] = "HTTP Version Not Supported";
}

HTTPServer::~HTTPServer()
{
    for (std::list<Client*>::iterator it = _clientList.begin(); it != _clientList.end(); it++)
        delete *it;
    _clientList.clear();
    for (std::list<int>::iterator it = sdList.begin(); it != sdList.end(); it++)
    {
        if (FD_ISSET(*it, &readMaster))
            FD_CLR(*it, &readMaster);
        if (FD_ISSET(*it, &writeMaster))
            FD_CLR(*it, &writeMaster);
        close(*it);
    }
    std::cout << "\033[1;37mGOOD BYE WEBSERV\033[0m" << std::endl;
}

/* SERVER INIT FUNCTIONS */
void    HTTPServer::loadConfig(std::string const &confFile)
{
    try
    {
        _cfgParser.load(confFile);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    _servCfg = _cfgParser.getCfgList();
}

void    HTTPServer::initServers(void)
{
    std::vector<ConfigServer>::iterator   it;
    std::vector<std::pair<int, std::string> > pairsPortHost;
    std::vector<std::pair<int, std::string> >::iterator itP;
    for (it = _servCfg.begin(); it != _servCfg.end(); it++)
    {
        std::pair<int, std::string> currentPair(it->getListen(), it->getHost());
        if (std::find(pairsPortHost.begin(), pairsPortHost.end(), currentPair) == pairsPortHost.end())
            pairsPortHost.push_back(currentPair);
    }
    for (itP = pairsPortHost.begin(); itP != pairsPortHost.end(); itP++)
    {
        setupTCP(itP->first, itP->second);
    }
}

void    HTTPServer::setupTCP(int port, std::string const &host)
{
    int     rc, listen_sd, on = 1;
    sockaddr_in sockaddr;

    // Create a socket (IPv4, TCP)
    listen_sd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sd == -1) {
      std::cerr << "Failed to create socket. " << strerror(errno) << std::endl;
      exit(EXIT_FAILURE);
    }
    // Allow socket to be reusable
    rc = setsockopt(listen_sd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
    if (rc < 0)
    {
        std::cerr << "Setsockopt failed. " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    // Set socket to non-blocking
    rc = fcntl(listen_sd, F_SETFL, O_NONBLOCK);
    if (rc < 0)
    {
        std::cerr << "Fcntl failed. " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    // Bind to config port on selected host ip
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(host.c_str());
    sockaddr.sin_port = htons(port);
    if (bind(listen_sd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0)
    {
        std::cerr << "Bind failed. " << strerror(errno) << std::endl;
        if (errno == EADDRNOTAVAIL || errno == EADDRINUSE)
        {
            std::cerr << "Please change the host " << host.c_str() << " in the config file." << std::endl;
        }
        for (std::vector<int>::iterator it = _sockets.begin(); it != _sockets.end(); it++)
            close(*it);
        exit(EXIT_FAILURE);
    }
    // Start listening. Hold at most Backlog connections in the queue
    if (listen(listen_sd, BACKLOG) < 0)
    {
        std::cerr << "Listen failed on socket " << listen_sd << ". " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    // Add each sockets to the listen_sd list
    _sockets.push_back(listen_sd);
}

void    HTTPServer::initFdSets()
{
    std::vector<int>::iterator  sd;

    FD_ZERO(&readMaster);
    FD_ZERO(&writeMaster);
    for (sd = _sockets.begin(); sd != _sockets.end(); sd++)
    {
        FD_SET(*sd, &readMaster);
        sdList.push_back(*sd);
    }
}

/* HTTP HANDLING FUNCTIONS */
void    HTTPServer::acceptNewConnection(int listen_sd)
{
    int new_sd;
    sockaddr_in sockaddr;
    socklen_t addrlen;
    
    addrlen = sizeof(sockaddr);
    new_sd = accept(listen_sd, (struct sockaddr*)&sockaddr, &addrlen);
    if (new_sd < 0)
    {
        std::cerr << "Failed to grab connection. " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    Client  *c = new Client(new_sd);
    c->setConfig(matchServerCfgs(c->getPort(), c->getIp()));
    _clientList.push_back(c);

    std::cout   << "  New incoming connection to port " << c->getPort()
                << ", client IP: " << c->getIp()
                << " - socket: " << new_sd << std::endl;

    sdList.push_back(new_sd);
    if (sdList.size() > MAX_CONNECTIONS)
    {
        std::cout << "In unavailable" << std::endl;
        c->setState(Unavailable);
        FD_SET(new_sd, &writeMaster);
    }
    else
    {
        FD_SET(new_sd, &readMaster);
    }
}

void    HTTPServer::handleRequest(Client *c)
{
    e_readState state = c->getState();
    std::string buf = c->getBufIn();
    if (state == StartLine)
    {
        c->initRequest();
        state = c->getRequest()->parseStartLine(buf, _implementedMethods);
    }
    if (state == Headers)
    {
        state = c->getRequest()->parseHeaders(buf, c->getConfigList());
    }
    if (state == Body)
    {
        state = c->getRequest()->parsePayload(buf);
    }
    c->setState(state);
}

int     HTTPServer::handleResponse(Client *c)
{
    if (c->getState() == Unavailable)
    {
        Response    *response = new Response();
        response->handleUnavailable();
        c->setBufOutput(generateResponse(response, ""));
        delete response;
    }
    else
    {
        Response    *response = new Response(c, _statusCodeMap);
        if (c->getState() == Error)
        {
            response->createErrorMsg();
        }
        else
        {
            response->executeMethod();
        }
        c->setBufOutput(generateResponse(response, c->getRequest()->getMethod()));
        Log     customLog(c->getRequest(), c->getIp(), response->getResponseCode());
        delete response;
    }
    return 0;
}

std::string HTTPServer::generateResponse(Response *r, std::string const &method)
{
    std::string newResponse;

    // Set Status Line
    newResponse.append("HTTP/1.1 " 
        + utils::intToString(r->getResponseCode()) 
        + " " + _statusCodeMap[r->getResponseCode()] + "\r\n");
    // Add Response Headers
    r->setResponseHeaders();
    std::map<std::string, std::string> headers = r->getResponseHeaders();
    std::map<std::string, std::string>::iterator it;
    for (it = headers.begin(); it!= headers.end(); ++it)
    {
        newResponse += (it->first + it->second + "\r\n");
    }
    newResponse.append("\r\n");
    // Add payload if any
    if (!r->getResponseBody().empty() && method != "HEAD")
        newResponse.append(r->getResponseBody());

    return newResponse;
}

void    HTTPServer::cleanConnection(Client *c)
{
    std::list<Client*>::iterator tmp = std::find(_clientList.begin(), _clientList.end(), c);
    if (tmp != _clientList.end())
        _clientList.erase(tmp);
    int connection = c->getSocket();
    if (FD_ISSET(connection, &readMaster))
        FD_CLR(connection, &readMaster);
    if (FD_ISSET(connection, &writeMaster))
        FD_CLR(connection, &writeMaster);
    std::list<int>::iterator found = std::find(sdList.begin(), sdList.end(), connection);
    if (found != sdList.end())
        sdList.erase(found);
    close(connection);
    delete (c);
}

/* UTILS */
std::vector<ConfigServer>   HTTPServer::matchServerCfgs(int port, std::string const &host)
{
    std::vector<ConfigServer>::iterator it;
    std::vector<ConfigServer>    matchedCfgs;

    for (it = _servCfg.begin(); it != _servCfg.end(); it++)
    {
        if (it->getListen() == port && it->getHost() == host)
            matchedCfgs.push_back(*it);
    }
    return matchedCfgs;
}

Client  *HTTPServer::matchClient(int connection)
{
    Client  *c = NULL;
    std::list<Client*>::iterator it;
    for (it = _clientList.begin(); it != _clientList.end(); it++)
    {
        if ((*it)->getSocket() == connection)
        {
            c = *it;
        }
    }
    return c;
}

/* GETTERS */
std::vector<int>    HTTPServer::getSockets(void)
{
    return _sockets;
}

std::list<Client*>  HTTPServer::getClientList(void)
{
    return _clientList;
}