#include "location.hpp"

Location::Location() : _clientMaxBodySize(-1), _hasBodySize(false)
{
}

Location::Location(Location const &other)
{
    *this = other;
}

Location &Location::operator=(Location const &other)
{
    this->_requestURI = other._requestURI;
    this->_root = other._root;
    this->_methods = other._methods;
    this->_index = other._index;
    this->_cgi = other._cgi;
    this->_auth = other._auth;
    this->_autoindex = other._autoindex;
    this->_clientMaxBodySize = other._clientMaxBodySize;
    this->_uploadPath = other._uploadPath;
    this->_hasBodySize = other._hasBodySize;
    return *this;
}

Location::~Location()
{
}

void    Location::setURI(std::string &buffer)
{
    _requestURI = buffer;
}

void    Location::setRoot(std::string &buffer)
{
    _root = buffer;
}

void    Location::setMethod(std::string &buffer)
{
    _methods = utils::split(buffer, ' ');
}

void    Location::setIndex(std::string &buffer)
{
    _index = buffer;
}

void    Location::setCgi(std::string &buffer)
{
    if (!_cgi.empty())
    {
        throw std::runtime_error("Cgi: already present");
    }

    std::vector<std::string>    cgi;
    std::string                 ext;
    std::string                 cgi_path;

    cgi = utils::split(buffer, ' ');
    if (cgi.size() != 2)
        throw std::runtime_error("Cgi: incorrect number of arguments. Expected <ext> <path>");
    
    ext = cgi.front();
    cgi_path = cgi.back();
    _cgi[ext] = cgi_path;
}

void    Location::setAutoindex(std::string &buffer)
{
    bool    idx;

    idx = (buffer == "on ") ? true : false;
    _autoindex = idx;
}

void    Location::setAuth(std::string &buffer)
{
    _auth = buffer;
}

void    Location::setMaxBodySize(std::string &buffer)
{
    if (_hasBodySize)
    {
        throw std::runtime_error("Client_max_body_size: already present once");
    }
    std::vector<std::string> bodySize = utils::split(buffer, ' ');
        if (bodySize.size() > 1)
    {
        throw std::runtime_error("Client_max_body_size: too many parameters");
    }
    _clientMaxBodySize = utils::stringToInt(bodySize[0]); // doesnt work if param = ex: 1ret332
    if (_clientMaxBodySize < 0)
    {
        throw std::runtime_error("Client_max_body_size: bad value");
    }
    _hasBodySize = true;
}

void    Location::setUploadPath(std::string &buffer)
{
    if (!_uploadPath.empty())
    {
        throw std::runtime_error("Upload_folder: already present");
    }
    buffer.erase(buffer.find_last_not_of(" ") + 1);
    _uploadPath = buffer;
}

std::string Location::getUri(void) const
{
    return _requestURI;
}

std::string Location::getRoot(void) const
{
    return _root;
}

std::vector<std::string>  Location::getMethod(void) const
{
    return _methods;
}

std::string Location::getIndex(void) const
{
    return _index;
}

std::map<std::string, std::string> Location::getCgi(void) const
{
    return _cgi;
}

bool    Location::getAutoindex(void) const
{
    return _autoindex;
}

std::string Location::getAuth(void) const
{
    return _auth;
}

int     Location::getClientMaxBodySize(void) const
{
    return _clientMaxBodySize;
}

std::string Location::getUploadPath(void)
{
    return _uploadPath;
}

void    Location::printLocation(void)
{
    std::cout << "requestURI: " << _requestURI << std::endl;
    std::cout << "root: " << _root << std::endl;
    if (!_methods.empty()) {
        for (std::vector<std::string>::iterator it = _methods.begin(); it != _methods.end(); it++)
            std::cout << "methods: " << *it << std::endl;
    }

    std::cout << "index: " << _index << std::endl;
    if (!_cgi.empty())
        std::cout << "cgi: " << _cgi.begin()->first << "=" << _cgi.begin()->second << std::endl;
    std::cout << "auth: " << _auth << std::endl;
    std::cout << "autoindex: " << _autoindex << std::endl;
    std::cout << "max size: " << _clientMaxBodySize << std::endl;
    std::cout << "upload: " << _uploadPath << std::endl;
    std::cout << std::endl;
}