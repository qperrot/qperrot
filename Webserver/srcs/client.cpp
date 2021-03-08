# include "client.hpp"

Client::Client() {}

Client::Client(int socket) 
    : _sockFd(socket), _bytesRead(0), _bytesSent(0),  _offset(0), _req(NULL)
{
    _state = StartLine;
    _timeLastRecv = utils::getTime();

    // set client info
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);
    getsockname(_sockFd, (struct sockaddr *)&sin, &len);
    _port = ntohs(sin.sin_port);
	_ip = inet_ntoa(sin.sin_addr);
}

Client::~Client()
{
    if (_req)
    {
        delete _req;
    }
}

int    Client::receiveReq(int connection)
{
    char buf[BUFSIZE + 1];

    resetTimeout();
    utils::ftBzero(&buf, BUFSIZE);
    _bytesRead = recv(connection, buf, BUFSIZE, 0);
    if (_bytesRead == 0 || _bytesRead == -1)
    {
        std::cerr << std::endl << "  Bytes read: " << _bytesRead << std::endl;
        std::cerr << "  Connection closed - socket : " << connection << std::endl << std::endl;
        return -1;
    }
    buf[_bytesRead] = '\0';
	_bufferIn += buf;
    return 0;
}

bool    Client::isDoneRecv()
{
    if (_state == StartLine)
    {
        size_t endPos = _bufferIn.rfind("\r\n"); 
        if (endPos != std::string::npos)
		    return true;
    }
    if (_state == Headers)
    {
        size_t endPos = _bufferIn.rfind("\r\n\r\n");
        if (endPos != std::string::npos)
		    return true;
    }
    if (_state == Body)
    {
        std::map<std::string, std::string> headers = _req->getHeadersMap();
	    size_t len = _bufferIn.length();

        if (utils::hasHeader("transfer-encoding:", headers)
            && headers["transfer-encoding:"].find("chunked") != std::string::npos)
        {
            size_t endSequencePos = _bufferIn.find("\r\n0\r\n\r\n", _offset);
	    	if (endSequencePos == std::string::npos && (_offset + _bytesRead) < len)
                _offset += _bytesRead;
            if ((endSequencePos != std::string::npos && endSequencePos + 7 == len))
            {
                _offset = 0;
	    		return true;
            }
        }
        else if (utils::hasHeader("content-length:", headers))
        {
            size_t payloadPos = _bufferIn.find("\r\n\r\n");
            if (payloadPos != std::string::npos && payloadPos + 4 < len)
                payloadPos += 4;
            std::string payload = _bufferIn.substr(payloadPos);
            if (payload.length() >= utils::stringToInt(headers["content-length:"]))
	    	    return true;
        }
    }
    return false;
}

int    Client::sendResponse()
{
    // std::cout << "\033[1;37mReady for send - socket : " << _sockFd << "\033[0m" << std::endl;
    
    delete _req;
    _req = NULL;
    _bufferIn.clear();
    _bufferIn.reserve(0);

    _bytesSent = 0;
    if (_bytesSent < static_cast<int>(_bufferOut.size()))
    {
        size_t length = _bufferOut.size();
        _bytesSent = send(_sockFd, _bufferOut.c_str(),  _bufferOut.size(), 0);
        if (_bytesSent == 0 || _bytesSent == -1)
        {
            std::cerr << "Error in send" << std::endl;
            return -1;
        }
        length -= _bytesSent;
        _bufferOut.erase(_bufferOut.begin(), _bufferOut.begin() + _bytesSent);
        _bufferOut.reserve(_bufferOut.size());
    }
    // std::cout << "Bytes sent: " << _bytesSent << std::endl;
    if (_bufferOut.empty() && _state != Unavailable)
    {
        _state = StartLine;
        return 0;
    }
    return 0;
}

void Client::resetTimeout()
{
	this->_timeLastRecv = utils::getTime();
}

bool Client::checkTimeout(time_t time)
{
	if (this->_timeLastRecv)
    {
		time_t diff = time - this->_timeLastRecv;
        // if inactive for more than **min, timeOut
		if (diff > (10 * 60))
		{	
            std::cout << "Connection Timed Out" << std::endl;
            return true;
        }
	}
    return false;
}

int             Client::getSocket()
{
    return _sockFd;
}

int             Client::getPort()
{
    return _port;
}

std::string     Client::getIp()
{
    return _ip;
}

Request         *Client::getRequest()
{
    return _req;
}

std::vector<ConfigServer> Client::getConfigList()
{
    return _cfgList;
}

e_readState     Client::getState()
{
    return _state;
}

std::string     Client::getBufIn()
{
    return _bufferIn;
}

std::string     Client::getBufOut()
{
    return _bufferOut;
}

void            Client::initRequest(void)
{
    _req = new Request;
}

void            Client::setConfig(std::vector<ConfigServer> cfgs)
{
    _cfgList = cfgs;
}

void            Client::setState(e_readState const &state)
{
    _state = state;
}

void            Client::setBufOutput(std::string const &response)
{
    _bufferOut = response;
}