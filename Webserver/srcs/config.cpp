#include "config.hpp"

ConfigServer::ConfigServer()
{
    _listen = 0;
}

ConfigServer &ConfigServer::operator=(ConfigServer const &other)
{
    _listen = other._listen;
    _host = other._host;
    _serverName = other._serverName;
    _errorPage = other._errorPage;
    _routesCfg = other._routesCfg;
    return *this;
}

ConfigServer::~ConfigServer()
{
}

void    ConfigServer::reset()
{
    utils::ftBzero(this, sizeof(ConfigServer));
    std::map<int, std::string> newMap;
    _errorPage = newMap;
    _host = "127.0.0.1";
}

void    ConfigServer::setListen(std::string &buffer)
{
    if (_listen)
    {
        throw std::runtime_error("Listen: already present in config");
    }
    std::vector<std::string> listenPort = utils::split(buffer, ' ');
    if (listenPort.size() > 1)
    {
        throw std::runtime_error("Listen: too many parameters");
    }
    try
    {
        _listen = utils::stringToInt(listenPort[0]);
    }
    catch (std::exception& e)
    {
        throw std::runtime_error(e.what());
    }
    if (_listen < 1024 || _listen > 65535)
    {
        throw std::runtime_error("Listen: port not in valid range");  
    }    
}

void    ConfigServer::setHost(std::string &buffer)
{
    buffer.erase(buffer.find_last_not_of(" ") + 1);
    _host = buffer;
    if (_host == "localhost")
    {
        _host = "127.0.0.1";
    }
}

void    ConfigServer::setServerName(std::string &buffer)
{
    if (!_serverName.empty())
    {
        throw std::runtime_error("Server_name: already present");
    }
    _serverName = utils::split(buffer, ' ');
}

void    ConfigServer::setErrPage(std::string &buffer)
{
    std::vector<std::string>    errPages(utils::split(buffer, ' '));
    std::string                 path;

    path = errPages.back();
    for (unsigned long i = 0; i < errPages.size() - 1; i++)
    {
        _errorPage[utils::stringToInt(errPages[i])] = path;
    }
}

void    ConfigServer::setLocation(Location &location)
{
    _routesCfg.push_back(location);
}

int     ConfigServer::checkIfValid(void)
{
    if (!_listen)
    {
        return ERR_PORT;
    }
    return OK_GOOD;
}

bool    ConfigServer::empty(void)
{
    return _listen == 0;
}

int     ConfigServer::getListen()
{
    return _listen; 
}

std::string ConfigServer::getHost(void)
{
    return _host;
}

std::vector<std::string>    ConfigServer::getServerName(void)
{
    return _serverName;
}

std::map<int, std::string>  ConfigServer::getErrorPage(void)
{
    return _errorPage;
};

std::vector<Location>       ConfigServer::getRoutes(void)
{
    return _routesCfg;
}

void    ConfigServer::print()
{
    std::vector<std::string>::iterator it;
    std::map<int, std::string>::iterator itm;
    std::vector<Location>::iterator itl;

    std::cout << "------- Printing config -------\n";
    std::cout << "listen: " << _listen << std::endl;
    std::cout << "host: " << _host << std::endl;
    if (!_serverName.empty()) {
        for (it = _serverName.begin(); it != _serverName.end(); it++)
            std::cout << "server_name: " << *it << std::endl;
    }
    else {
        std::cout << "server_name: empty\n";
    }

    if (!_errorPage.empty()) {
        for (itm = _errorPage.begin(); itm != _errorPage.end(); itm++)
            std::cout << "error_page: " << itm->first << " = " << itm->second << std::endl;
    }
    else {
        std::cout << "error_pages: 0\n";
    }    
    std::cout << "\nLocations\n";
    if (!_routesCfg.empty()) {
        for (itl = _routesCfg.begin(); itl != _routesCfg.end(); itl++)
            itl->printLocation();
    }
    else {
        std::cout << "locations: 0\n";
    }

    std::cout << "------- End config -------\n";
    std::cout << std::endl;
}