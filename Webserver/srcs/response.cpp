#include "response.hpp"

Response::Response()
{
}

Response::Response(Client *c, std::map<int, std::string> statusCodeMap)
    : _req(c->getRequest()), _ip(c->getIp()), _port(c->getPort()), _statusCodeMap(statusCodeMap)
{
    this->_responseCode = _req->getStatusCode();
    this->_requestPayload = _req->getPayload();
    this->_cfg = _req->getConfig();
    _responseHeaders.clear();
    _responseBody.clear();
}

Response::~Response()
{
    _responseBody.clear();
    _responseBody.reserve(0);
}

void    Response::executeMethod(void)
{
    if (this->_responseCode == 400)
    {
        createErrorMsg();
        return;
    }
    if (!_req->getTargetPath().empty())
        this->_locat = findLocation(_cfg, _req->getTargetPath());
    this->_resourcePath = createPath();
    if (!checkMaxBodySize() || !checkAuthorization() || !checkMethod())
    {
        createErrorMsg();
        return;
    }
    // *** ResponseHandler ***
    if (!_locat.getCgi().empty() && hasCGIext(_req->getTargetPath(), _locat.getCgi().begin()->first))
        handleCgi();
    else if (_req->getMethod() == "GET")
        handleGet();
    else if (_req->getMethod() == "HEAD")
        handleHead();
    else if (_req->getMethod() == "POST")
        handlePost();
    else if (_req->getMethod() == "PUT")
        handlePut();
}

void    Response::handleCgi(void)
{
    std::cout << "IN CGI\n";
    std::map<std::string,std::string> tmpHeaders;
    std::map<std::string,std::string>::iterator it;

    CGI cgi(_req, _locat, _resourcePath, _requestPayload, _port, _ip);
    if (!cgi.execCGI())
    {
        _responseCode = cgi.getStatusCode();
        createErrorMsg();
        return;
    }
    cgi.parseOutput();
    _responseCode = cgi.getStatusCode();
    tmpHeaders = cgi.getHeaders();
    for (it = tmpHeaders.begin(); it != tmpHeaders.end(); it++)
    {
        _responseHeaders.insert(*it);
    }
    _responseBody.append(cgi.getPayload());
}

bool    Response::hasCGIext(std::string const &targetPath, std::string const &confCGIExt)
{
    std::string uriExt;

    uriExt = targetPath.substr(targetPath.find_last_of('.') + 1);
    return (uriExt == confCGIExt);
}

void    Response::handleGet(void)
{
    // std::cout << "In GET Method Handler" << std::endl;

    struct stat buf;
    if (stat(_resourcePath.c_str(), &buf) == -1)
    {
        _responseCode = 404;
        createErrorMsg();
        return ;
    }
    if (S_ISREG(buf.st_mode))
    {
        int     fd;
        if ((fd = open(_resourcePath.c_str(), O_RDONLY)) != -1)
        {
            setResponseBody(_resourcePath);
            close(fd);
            return ;
        }
        _responseCode = 403;
        createErrorMsg();
    }
    else if (S_ISDIR(buf.st_mode))
    {
        if (!(_locat.getIndex().empty()))
        {
            if (handleIndex())
                setResponseBody(_resourcePath);
            else
                createErrorMsg();
        }
        else if (_locat.getAutoindex())
        {
            autoIndex(_req->getTargetPath());  
        }
        else
        {
            _responseCode = 404;
            createErrorMsg();
        }
    }
}

void    Response::handleHead(void)
{
    // std::cout << "In HEAD Method Handler" << std::endl;
    handleGet();
}

void    Response::handlePost(void)
{
    // std::cout << "In POST Method Handler" << std::endl;
    struct stat buf;
    int         fd;
    
    if (stat(_resourcePath.c_str(), &buf) == -1)
    {
        if (!_locat.getUploadPath().empty())
        {
            std::string tmplocat = _locat.getRoot();
            if (tmplocat[0] == '/')
                tmplocat.insert(0, ".");
            if (tmplocat[0] != '.')
                tmplocat.insert(0, "./");
            std::string tmpPath = _resourcePath.substr(tmplocat.size() - 1);
            _resourcePath.clear();
            _resourcePath = _locat.getUploadPath().substr(0);
            if (_resourcePath[0] == '/')
                _resourcePath.insert(0, ".");
            if (_resourcePath[0] != '.')
                _resourcePath.insert(0, "./");
            _resourcePath += tmpPath;
        }
        if (stat(_resourcePath.c_str(), &buf) == -1)
        {
            if ((fd = open(_resourcePath.c_str(), O_CREAT | O_WRONLY, 0666)) == -1)
            {
                _responseCode = 500;
                close(fd);
                return;
            }
            _responseCode = 201;
            _responseHeaders["Location: "] = _resourcePath;
        }
    }
    if (stat(_resourcePath.c_str(), &buf) != -1 && S_ISREG(buf.st_mode))
    {
        if ((fd = open(_resourcePath.c_str(), O_WRONLY | O_APPEND, 0666)) != -1)
        {
            writeInFile(fd);
            close(fd);
            return;
        }
        _responseCode = 403;
        createErrorMsg();
    }
    else if (stat(_resourcePath.c_str(), &buf) != -1 &&  S_ISDIR(buf.st_mode))
    {
        if (handleIndex())
        {
            if ((fd = open(_resourcePath.c_str(), O_WRONLY | O_APPEND, 0666)) != -1)
            {
                writeInFile(fd);
                close(fd);
                return;
            }
            _responseCode = 403;
        }
        createErrorMsg();
    }
}

void    Response::handlePut(void)
{
    // std::cout << "In PUT Method Handler" << std::endl;

    struct stat buf;
    int         fd;
    
    if (stat(_resourcePath.c_str(), &buf) == -1)
    {
        if (!_locat.getUploadPath().empty())
        {
            std::string tmplocat = _locat.getRoot();
            if (tmplocat[0] == '/')
                tmplocat.insert(0, ".");
            if (tmplocat[0] != '.')
                tmplocat.insert(0, "./");
            std::string tmpPath = _resourcePath.substr(tmplocat.size() - 1);
            _resourcePath.clear();
            _resourcePath = _locat.getUploadPath().substr(0);
            if (_resourcePath[0] == '/')
                _resourcePath.insert(0, ".");
            if (_resourcePath[0] != '.')
                _resourcePath.insert(0, "./");
            _resourcePath += tmpPath;
        }
        if (stat(_resourcePath.c_str(), &buf) == -1)
        {
            if ((fd = open(_resourcePath.c_str(), O_CREAT | O_WRONLY, 0666)) == -1)
            {
                _responseCode = 500;
                close(fd);
                return;
            }
            _responseCode = 201;
            _responseHeaders["Location: "] = _req->getTargetPath();
        }
    }
    if (stat(_resourcePath.c_str(), &buf) != -1 &&  S_ISREG(buf.st_mode))
    {
        if ((fd = open(_resourcePath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0666)) != -1)
        {
            writeInFile(fd);
            _responseBody.clear();
            close(fd);
            return;
        }
        _responseCode = 403;
    }
    else if (stat(_resourcePath.c_str(), &buf) != -1 && S_ISDIR(buf.st_mode))
    {
        if (handleIndex())
        {
            if ((fd = open(_resourcePath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0666)) != -1)
            {
                writeInFile(fd);
                _responseBody.clear();
                close(fd);
                return;
            }
            _responseCode = 403;
        }
    }
}

void    Response::handleUnavailable(void)
{
    _responseCode = 503;
    _responseHeaders["Retry-After: "] = "120";
    setResponseBody(DEFAULT_ERR_FILE);
    customizeErrorResponse();
}

bool    Response::handleIndex(void)
{
    struct stat buf;

    if (!(_locat.getIndex().empty()))
    {
        std::vector<std::string> index = utils::split(_locat.getIndex(), ' ');
        std::vector<std::string> content_neg = contentNegociation(index, _resourcePath);

        if (!(content_neg.empty()))
            index = content_neg;
        std::string tmp;
        for (std::vector<std::string>::iterator it = index.begin(); it != index.end(); ++it)
        {
            tmp = _resourcePath;
            if (utils::back(tmp) != '/')
                tmp = tmp + "/";
            tmp += (*it);
            if (stat(tmp.c_str(), &buf) != -1)
            {
                _resourcePath = tmp;
                if (S_ISREG(buf.st_mode))
                {
                    int fd;
                    if ((fd = open(_resourcePath.c_str(), O_RDONLY)) != -1)
                    {
                        close(fd);
                        return true;
                    }
                    else
                    {
                        _responseCode = 403;
                        return false;
                    }
                }
            }
            tmp.clear();
        }
        if (tmp.empty())
        {
            _responseCode = 404;
            return false;
        }
    }
    _responseCode = 404;
    return false;
}

void    Response::autoIndex(std::string const &targetPath)
{
    DIR     *dir;

    dir = opendir(_resourcePath.c_str());
    std::string tmpPath = targetPath;
    if (tmpPath.find_last_of("/") != tmpPath.size() - 1)
        tmpPath += "/";

    struct dirent *dp;
    std::string HtmlPage = "<head>\n<title>Index of " + _locat.getUri() 
                        + "</title>\n</head>\n<body>\n<h1>Index of " + _locat.getUri() 
                        + "</h1>\n<hr><pre>\n";

    while ((dp = readdir(dir)) != NULL)
    {
        HtmlPage += std::string("<a ") + "href=\"" + tmpPath 
                 + std::string(dp->d_name) + "\">" + std::string(dp->d_name)
                 + "</a>" + "\n" ;
    }
    HtmlPage += "\t</pre><hr>\n</body>\n</html>";
    _responseBody.append(HtmlPage);
    closedir(dir);
}

std::vector<std::string>  Response::contentNegociation(std::vector<std::string> index, std::string path)
{
    std::vector<std::string>    acceptLang;
    std::vector<std::string>    acceptCharset;
    std::vector<std::string>    ListacceptLang;
    std::vector<std::string>    ListacceptCharset;
    std::vector<std::string>    NewIndex;
    std::string                 tmp;
    std::vector<std::string>    tmpLang;
    std::vector<std::string>::iterator it;
    std::map<std::string, std::string> req = _req->getHeadersMap();

    if (req.count("accept-language:"))
        acceptLang = utils::parseByWeight(req["accept-language:"]);
    if (req.count("accept-charset:"))
        acceptCharset = utils::parseByWeight(req["accept-charset:"]);

    ListacceptLang = createContentsList(acceptLang, index, path, "lang");
    ListacceptCharset = createContentsList(acceptCharset, index, path, "charset");

    for (std::vector<std::string>::iterator it_in3 = ListacceptLang.begin(); it_in3 != ListacceptLang.end(); ++it_in3)
    {
        for (it = ListacceptCharset.begin(); it != ListacceptCharset.end(); it++)
        {
            if ((*it).compare(*it_in3) == 0)
            {
                NewIndex.push_back(*it);
                return NewIndex;
            }
        }   
    }
    if (!ListacceptCharset.empty())
        NewIndex.push_back(ListacceptCharset[0]);
    else if (!ListacceptLang.empty())
        NewIndex.push_back(ListacceptLang[0]);
    return NewIndex;
}

std::vector<std::string>    Response::createContentsList(std::vector<std::string> acceptLang, std::vector<std::string> index, std::string path, std::string word)
{
    std::string                 tmp;
    std::vector<std::string>    tmpLang;
    std::vector<std::string>    ListacceptLang;

    for (std::vector<std::string>::iterator it2=acceptLang.begin(); it2!=acceptLang.end(); ++it2)
    {
        for (std::vector<std::string>::iterator it_in=index.begin(); it_in!=index.end(); ++it_in)
        {
            std::string tmpPath = path + (*it_in);
            std::ifstream ifs(tmpPath.c_str());
            if (ifs.bad())
            {
                throw std::runtime_error("Failed to open " + tmpPath + " for reading.");
            }
            std::istream &input = ifs;
            while (std::getline(input, tmp))
            {
                std::string lang_char;
                if (tmp.find(word) != std::string::npos)
                {
                    std::size_t found = tmp.find(word) + word.size();
                    if (tmp[found] == '=')
                        found++;
                    else
                        break;
                    if (tmp[found] == '\"')
                        found++;
                    else
                        break;
                    std::string langTMP(tmp, found, tmp.size());
                    for (size_t i = 0; i < langTMP.size(); i++)
                    {
                        if (langTMP[i] != '\"')
                           lang_char.push_back(langTMP[i]);
                        else
                            break;
                    }
                    if (utils::stringTolower(lang_char).compare(utils::stringTolower((*it2))) == 0)
                    {
                        ListacceptLang.push_back((*it_in));
                        break;
                    }
                }
            }
            ifs.close();
        }
    }
    return ListacceptLang;
}

void    Response::writeInFile(int fd)
{
    if (utils::writeThroughSelect(fd) != -1)
    {
        std::map<std::string, std::string> req = _req->getHeadersMap();
        if (req.count("content-length:"))
        {
            int len = utils::stringToInt((req["content-length:"]).c_str());
            if (write(fd, _requestPayload.c_str(), len) == -1)
                _responseCode = 500;  
        }
        else if (req.count("transfer-encoding:"))
        {
            if (write(fd, _requestPayload.c_str(), _requestPayload.size()) == -1)
                _responseCode = 500;
        }
        if (_responseCode == 200)
            _responseHeaders["Content-Location: "] = _req->getTargetPath();
        if (_responseCode < 300)
            setResponseBody(_resourcePath);
    }
    else
        _responseCode = 500;
    return;
}

void    Response::createErrorMsg(void)
{
    std::string errorPage;
    if (!_cfg.empty())
    {
        std::map<int,std::string> cfgErrPages = _cfg.getErrorPage();
        std::map<int,std::string>::iterator it;

        for (it = cfgErrPages.begin(); it != cfgErrPages.end(); it++)
        {
            if (it->first == _responseCode)
            {
                errorPage = it->second;
                setResponseBody(errorPage);
            }
        }
    }
    if (errorPage.empty())
    {
        setResponseBody(DEFAULT_ERR_FILE);
        customizeErrorResponse();
    }
}

void    Response::setResponseBody(std::string file)
{
    int fd;
    std::string buffer;
    struct stat sb;

    std::size_t found = file.find_first_of("/");
    if (found == 0)
        file.insert(0, ".");  
    buffer.clear();
    if ((fd = open(file.c_str(), O_RDONLY)) == -1)
        return ;
    fstat(fd, &sb);
    buffer.resize(sb.st_size);

    if (utils::readThroughSelect(fd) == -1)
        return ;
    if (read(fd, const_cast<char*>(buffer.data()), sb.st_size) == -1)
        return ;
    close(fd);
    _responseBody = buffer;
}

void    Response::setResponseHeaders(void)
{
    // HEADER CONTENT_LENGTH
    long length = _responseBody.size();
     _responseHeaders["Content-Length: "] = utils::intToString(length);

    // HEADER CONTENT_LANGUAGE
    std::size_t pos;
    std::size_t endPos;
    std::string charset;
    charset.clear();
    
    pos = _responseBody.find("lang=\"");
    if (pos != std::string::npos)
    {
        endPos = _responseBody.find("\"", pos + 6);
        if (endPos != std::string::npos)
        {
            _responseHeaders["Content-Language: "] = utils::stringTolower(_responseBody.substr(pos + 6, endPos - (pos + 6)));
        }
    }
    pos = _responseBody.find("charset=\"");
    if (pos != std::string::npos)
    {
        endPos = _responseBody.find("\"", pos + 9);
        if (endPos != std::string::npos)
        {
            charset = utils::stringTolower(_responseBody.substr(pos + 9, endPos - (pos + 9)));
        }
    }

    // HEADER CONTENT_TYPE
    pos = _resourcePath.find_last_of(".");
    std::string tmp (_resourcePath.begin() + pos + 1, _resourcePath.end());
    std::map<std::string, std::string>  mime_type;
    mime_type = utils::parseMime();
    for (std::map<std::string, std::string>::iterator itm=mime_type.begin(); itm!=mime_type.end(); ++itm)
    {
        if (pos != std::string::npos)
        {
            if (utils::stringTolower(itm->first).compare(utils::stringTolower(tmp)) == 0)
            {
                if (!charset.empty())
                {
                    itm->second += std::string("; charset=") + charset;
                }
                _responseHeaders["Content-Type: "] = itm->second;
                break;
            }
        }
    }
    mime_type.clear();

    // HEADER DATE
    _responseHeaders["Date: "] = utils::dateHeader();                                                             

    // HEADER LAST_MODIFIED
    _responseHeaders["Last-Modified: "] = utils::lastModifiedHeader(_resourcePath);
    if (_responseHeaders["Last-Modified: "] == "")
        _responseHeaders.erase("Last-Modified: ");

    // HEADER ALLOW
    if (_responseCode == 405)
    {
        std::string     allow;
        std::vector<std::string> method = _locat.getMethod();
	    for (std::vector<std::string>::iterator it=method.begin(); it!=method.end(); ++it)
	    {
            if (it != method.begin())
                allow.append(", ");
		    allow += (*it);
	    }
        _responseHeaders["Allow: "] = allow;
        std::cout << "Allow: " << _responseHeaders["Allow: "] << std::endl;
    }
    if (_responseCode == 401)
        _responseHeaders["WWW-Authenticate: "] = "Basic realm=\"User Visible Realm\"";

    // HEADER SERVER
    _responseHeaders["Server: "] = "webserv";
}

void    Response::customizeErrorResponse(void)
{
    size_t pos;
    if ((pos = _responseBody.find("ERROR")) != std::string::npos)
        _responseBody.replace(pos, 5, utils::intToString(_responseCode));
    if ((pos = _responseBody.find("MSG")) != std::string::npos)
        _responseBody.replace(pos, 3, _statusCodeMap[_responseCode]);
}

bool    Response::checkMaxBodySize(void)
{
    if (_locat.getClientMaxBodySize() == -1)
        return true;
    if (static_cast<int>(_requestPayload.size()) > _locat.getClientMaxBodySize())
    {
        std::cerr << "Error: Above Max body size" << std::endl;
        _responseCode = 413;
        return false;
    }
    return true;
}

bool    Response::checkAuthorization()
{
    if (!_locat.getAuth().empty())
    {
        std::map<std::string, std::string> _requestHeaders = _req->getHeadersMap();
        std::string password = _locat.getAuth(); 
        if (password.find_last_of(" ") != std::string::npos)
            password.erase(password.find_last_of(" "), 1);
        if (_requestHeaders.count("authorization:"))
        {
            std::string authorization = _requestHeaders["authorization:"];
            std::string basic;
            for (size_t i = 0; i < authorization.size() ; i++)
            {
                if (authorization[i] == ' ')
                    break;
                basic.push_back(authorization[i]);
            }
            if ((utils::stringTolower(basic)).compare("basic") == 0)
            {
                std::string givenPassword(authorization, 6, (authorization.size() - 6));
                givenPassword = utils::base64Decode(givenPassword);
                if (givenPassword.compare(password) != 0)
                {
                    _responseCode = 401;
                    return false;
                }
            }
        }
        else
        {
            _responseCode = 401;
            return false;
        }
    }
    return true;
}

bool   	Response::checkMethod(void)
{
    if (_locat.getMethod().empty())
        return true;
	std::vector<std::string> method = _locat.getMethod();
	for (std::vector<std::string>::iterator it = method.begin(); it != method.end(); ++it)
	{
		if ((*it).compare(_req->getMethod()) == 0)
			return true;
	}
    _responseCode = 405;
	return false;
}

Location    Response::findLocation(ConfigServer &conf, std::string targetPath)
{
	Location	locat;
	std::vector<Location> tmp = conf.getRoutes();

	for (std::vector<Location>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
    {
        if (((*it).getUri()).compare(targetPath) == 0)
        {
			locat = (*it);
			return locat;
        }
    }
	for (std::vector<Location>::reverse_iterator it=tmp.rbegin(); it!=tmp.rend(); ++it)
    {
		std::string tmpdir = targetPath;
		while (tmpdir.length() > 0)
		{
			if (((*it).getUri()).compare(tmpdir) != 0)
			{
				size_t found = tmpdir.find_last_of("/");
				if (found != std::string::npos)
					tmpdir.erase(tmpdir.begin() + found, tmpdir.end());
				if (((*it).getUri()).compare(tmpdir) == 0)
				{
					locat = (*it);
					return locat;
				}
				else
				{
					found = tmpdir.find_last_of("/");
					if (found != std::string::npos)
						tmpdir.erase(tmpdir.begin() + found, tmpdir.end());
				}
				if (tmpdir.length() > 0 && utils::back(tmpdir) != '/')
					tmpdir = tmpdir + '/';
			}
			else
			{
				locat = (*it);
				return locat;
			}	
		}
    }
	std::vector<Location>::iterator it=tmp.begin();
	return (*it);
}

std::string Response::createPath(void)
{
    std::string path;
    std::string tmp;
    std::size_t found = _req->getTargetPath().find(_locat.getUri());

    tmp = _req->getTargetPath();
    tmp.erase(found, (_locat.getUri()).size());
    path = _locat.getRoot();
    while (utils::back(path) == ' ')
        path.erase(path.length() - 1, 1);
    if (utils::back(path) != '/' && tmp[0] != '/')
        path = path + "/";
    path = path + tmp;
    if (path.find_first_of("/") == 0)
        path.insert(0, ".");
    return path;
}

int Response::getResponseCode(void)
{
    return _responseCode;
}

std::map<std::string, std::string>  Response::getResponseHeaders(void)
{
    return _responseHeaders;
}

std::string Response::getResponseBody(void)
{
    return _responseBody;
}