# include "request.hpp"

Request::Request()
{
    _statusCode = 200;
}

Request::Request(Request const &other)
{
    *this = other;
    return ;
}

Request::~Request()
{
    _requestPayload.clear();
    _requestPayload.reserve(0);
}

e_readState Request::parseStartLine(std::string &requestBuf, std::vector<std::string> &implementedMethods)
{
    size_t endline;
    if ((endline = requestBuf.find("\r\n")) == std::string::npos)
        return StartLine;
    
    _startLine = requestBuf.substr(0, endline);
    if (std::count(_startLine.begin(), _startLine.end(), ' ') > 2)
	{
		this->_statusCode = 400;
		return Error;
	}
    std::vector<std::string> requestLine = utils::split(_startLine, ' ');
	if (requestLine.size() < 3 || requestLine.size() > 3)
	{
		this->_statusCode = 400;
		return Error;
	}
	this->_method = requestLine[0];
	this->_requestUri = requestLine[1];
	this->_version = requestLine[2];
    if (!checkMethod(implementedMethods) || !checkUri() || !checkVersion())
        return Error;
    return Headers;
}

e_readState Request::parseHeaders(std::string &requestBuf, std::vector<ConfigServer> cfgList)
{
    if (requestBuf.find("\r\n\r\n") == std::string::npos)
    {
        return Headers;
    }
    std::string headers;
    size_t beginPos = requestBuf.find("\r\n") + 2; 
    size_t endPos = requestBuf.find("\r\n\r\n");
    headers = requestBuf.substr(beginPos, endPos);
    if (!parseToMap(headers) || !checkHeaders())
    {
        return Error;
    }
    _cfg = getCorrectConfig(cfgList);
    if (utils::hasHeader("transfer-encoding:", _headersMap)
        || utils::hasHeader("content-length:", _headersMap))
    {
        return Body;
    }
    return Complete;
}

e_readState Request::parsePayload(std::string &requestBuf)
{
	size_t len = requestBuf.length();
    size_t payloadPos = requestBuf.find("\r\n\r\n");
    if (payloadPos != std::string::npos && payloadPos + 4 < len)
        payloadPos += 4;
    _requestPayload = requestBuf.substr(payloadPos);

    if (utils::hasHeader("transfer-encoding:", _headersMap))
    {
        if (_headersMap["transfer-encoding:"].find("chunked") != std::string::npos)
        {
            // std::cout << "Parsing Chunked TE Payload" << std::endl;
            size_t endSequencePos = requestBuf.find("\r\n0\r\n\r\n");
		    if (endSequencePos != std::string::npos && endSequencePos + 7 == len)
            {
                if (!decodeChunkedBody())
                {
                    _statusCode = 400;
                    return Error;
                }
		    	return Complete;
            }
        }
        else
        {
            _statusCode = 501;
            return Error;  
        }
    }
    if (utils::hasHeader("content-length:", _headersMap))
    {
        if (_requestPayload.length() >= utils::stringToInt(_headersMap["content-length:"]))
        {
		    return Complete;
        }
    }

    return Body;
}

bool    Request::decodeChunkedBody()
{
    std::string payload = _requestPayload;
    _requestPayload.clear();
    size_t  i = 0;
    size_t j = 1;
    long len = 0;
    while (i < payload.size())
    {
        std::string tmp;
        if (j % 2 != 0)
        {
            size_t found = payload.find("\r\n", i);
            if (found == std::string::npos)
                break;
            while (payload[i] && i < found)
            {
                if (IS_MIN_hexa(payload[i]))
                    payload[i] = payload[i] - 32;
                if (utils::hex_chars.find(payload[i]) != std::string::npos)
                {
                    tmp.push_back(payload[i]);
                    i++;
                }
                else
                {
                    return false;
                }
            }
            i += 2;
            len = utils::hexaToLong(tmp);
            j++;
        }
        else if (j % 2 == 0)
        {
            if (len == 0)
            {
                size_t k = i;
                if (payload.find("\r\n", i) != k)
                {
                    return false;
                }
            }
            else
            {
                while (len > 0 && i < payload.size())
                {
                    _requestPayload.push_back(payload[i]);
                    i++;
                    len--;
                }
            }
            while (i < payload.size())
            {
                if (payload[i] != '\r' && payload[i] != '\n')
                {
                    i++;
                }
                else
                    break;
            }
            if (i < payload.size())
                while (payload[i] == '\r' || payload[i] == '\n')
                    i++;
            j++;
        }
    }
    return true;
}

bool 	Request::checkMethod(std::vector<std::string> &implementedMethods)
{
    size_t maxLen = 0;
    for (std::vector<std::string>::iterator it = implementedMethods.begin(); it != implementedMethods.end(); it++)
    {
        if (it->length() > maxLen)
            maxLen = it->length();
    }
    if (_method.length() > maxLen)
    {
        _statusCode = 501;
        return false;
    }
    return true;
}

bool 	Request::checkUri(void)
{
    if (_requestUri.length() >= MAX_URI_LEN)
    {
        _statusCode = 414;
        return false;
    }
	size_t found = 0;
	if (_requestUri[0] != '/')
	{
		_statusCode = 400;
		return false;
	}

	if (_requestUri.find("?") != std::string::npos)
	{
		if (found != 0)
			_targetPath.append(_requestUri.begin()+found, _requestUri.begin() + _requestUri.find("?"));
		else
			_targetPath.append(_requestUri.begin(), _requestUri.begin() + _requestUri.find("?"));
		_queryString.append( _requestUri.begin() + _requestUri.find("?") + 1, _requestUri.end());
		return true;
	}
	else
	{
		if (found != 0)
			_targetPath.append(_requestUri.begin()+found, _requestUri.end());
		else
			_targetPath.append(_requestUri.begin(), _requestUri.end());
	}
	for (size_t i = 0; i < _targetPath.length(); i++)
	{
		if (_targetPath[i] == '/')
			_targetPath.erase(i, 1);
		else
			break;
		i = 0;
	}
	_targetPath = utils::convertHex(_targetPath);
	if (_targetPath[0] != '/')
		_targetPath.insert(0, "/");
    return true;
}

bool 	Request::checkVersion(void)
{
	size_t first = _version.find("HTTP/");
	if (first == std::string::npos)
	{
		_statusCode = 400;
		return false;
	}
	size_t period = _version.find_first_of(".", first + 4);
    if (period == std::string::npos)
	{
		_statusCode = 400;
		return false;
	}
	std::string major;
	major.append(_version.begin()+ first + 4 + 1, _version.begin() + period);
	for (size_t i = 0; i < major.length(); i++)
	{
		if (IS_DIGIT(major[i]) == false)
		{
			_statusCode = 400;
			return false;
		}
	}
	if (major.length() > 1 || major[0] != '1')
	{
		_statusCode = 505;
		return false;
	}
	std::string minor;
	minor.append(_version.begin() + period + 1, _version.end());
	if (minor.length() > 1 || minor[0] != '1')
	{
		_statusCode = 400;
		return false;
	}
    return true;
}

bool    Request::parseToMap(std::string &headerStr)
{
    size_t offset = 0;
    size_t endPos;
    std::string line;
    while ((endPos = headerStr.find_first_of("\r\n", offset)) != std::string::npos)
    {  
        line.clear();
        line = headerStr.substr(offset, endPos - offset);
        size_t colonPos;
        if ((colonPos = line.find(":")) != std::string::npos)
        {
            std::string name = line.substr(0, colonPos + 1);
            std::string value = line.substr(colonPos + 1);
            name = utils::stringTolower(name);
            value = utils::eraseOWS(value);
            if (utils::hasHeader(name, _headersMap) || name.length() == 1)
            {
                _statusCode = 400;
                return false;
            }
            _headersMap[name] = value;
        }
        offset = endPos + 2;
    }
    return true;
}

bool    Request::checkHeaders(void)
{
    std::map<std::string, std::string>:: iterator it;
    for (it = _headersMap.begin(); it != _headersMap.end(); it++)
    {
        if ((it->first).find_last_of(WHITESPACE) != std::string::npos
            || it->second.length() > 300 || it->first.length() > 50)
        {
            // std::cerr << "Error Syntax header field" << std::endl;
		    _statusCode = 400;
		    return false;
	    }
    }
    if (_headersMap.find("host:") == _headersMap.end())
	{
		_statusCode = 400;
		return false;
	}
    if (_headersMap.find("transfer-encoding:") != _headersMap.end()
        && _headersMap.find("content-length:") != _headersMap.end())
    {
		_statusCode = 400;
		return false;
	}
    if (_headersMap.find("content-length:") != _headersMap.end())
    {
        std::string value = _headersMap["content-length:"];
        if (value.find_first_not_of("0123456789") != std::string::npos
            || value.length() > 10)
        {
            _statusCode = 400;
		    return false;
        }
    }
    return true;
}

ConfigServer Request::getCorrectConfig(std::vector<ConfigServer> cfgList)
{
    ConfigServer cfg;
    size_t colonPos;
    std::string reqHost = _headersMap["host:"];
    if ((colonPos = reqHost.find(":")) != std::string::npos)
    {
        reqHost = reqHost.substr(0, colonPos);
    }
    for (std::vector<ConfigServer>::iterator it = cfgList.begin(); it != cfgList.end(); it++)
    {
        std::vector<std::string> serverNames = it->getServerName();
        if (std::find(serverNames.begin(), serverNames.end(), reqHost) != serverNames.end())
        {
            cfg = *it;
            break ;
        }
    }
    if (cfg.empty())
    {    
        cfg = cfgList.front();
    }
    return cfg;
}

std::string Request::getStartLine(void)
{
    return _startLine;
}


int     Request::getStatusCode(void)
{
    return _statusCode;
}

std::map<std::string, std::string>  Request::getHeadersMap(void)
{
    return _headersMap;
}

std::string Request::getTargetPath(void)
{
    return _targetPath;
}

std::string Request::getQueryString(void)
{
    return _queryString;
}

std::string Request::getMethod(void)
{
    return _method;
}

std::string Request::getVersion(void)
{
    return _version;
}

std::string Request::getPayload(void)
{
    return _requestPayload;
}

ConfigServer Request::getConfig(void)
{
    return _cfg;
}

std::string Request::getHeaderValue(std::string const &headerName) const
{
	if (_headersMap.find(headerName) == _headersMap.end())
    {
		return "";
    }
	return _headersMap.find(headerName)->second;
}

void    Request::printRequest(void)
{
    std::cout << "\n-------- REQUEST INFOS --------\n" << std::endl;
    std::cout << "Method: " << _method << std::endl;
    std::cout << "RequestUri: " << _requestUri << std::endl;
    std::cout << "Version: " << _version << std::endl;
    
    std::cout << "\nTargetPath: " << _targetPath << std::endl;
    std::cout << "QueryStr: " << _queryString << std::endl;

    std::cout << "\nHeaders: " << std::endl;
    if (!_headersMap.empty())
    {
        for (std::map<std::string, std::string>::iterator it = _headersMap.begin(); it != _headersMap.end(); it++)
            std::cout << it->first << " " << it->second << std::endl;
    }
    // std::cout << "\nPayload: *" << _requestPayload << "*" << std::endl;

    std::cout << "StatusCode: " << _statusCode << std::endl;
    std::cout << "\n--------      END      --------\n" << std::endl;
}