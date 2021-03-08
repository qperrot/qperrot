#include "cgi.hpp"

CGI::CGI(Request *req, Location locat, std::string &path, std::string &payload, int port, std::string &ip)
    : _request(req), _locat(locat), _resourcePath(path), _requestPayload(payload), _port(port), _ip(ip)
{
    _ext = _locat.getCgi().begin()->first;
    _cgiPath = _locat.getCgi().begin()->second;
    _auth = _locat.getAuth();
    _fullPath = translatePath();
    _env = NULL;
    _argv = NULL;
}

CGI::~CGI()
{
    utils::freeTab(_argv);
    utils::freeTab(_env);
}

bool    CGI::execCGI()
{
    setCGIenv();
    // printEnv(); // for debug

    if (!(_argv = (char **)(malloc(sizeof(char *) * 3))))
    {
        return processErr("Error: Malloc Exec CGI");
    }
    _argv[0] = utils::ftStrdup(_cgiPath.c_str());
    _argv[1] = utils::ftStrdup(_resourcePath.c_str());
    _argv[2] = NULL;

    int pipe_fd[2];
    if (pipe(pipe_fd))
	{
		return processErr("Error: CGI pipe");
	}
    pid_t pid = fork();
    if (pid < 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return processErr("Error: CGI fork");
	}
    else if (pid == 0)
    {
        int tmpFd;
        if ((tmpFd = open(TMPFILE, O_WRONLY | O_CREAT, 0666)) == -1)
        {
			std::cerr << "Error: open in child" << std::endl;
            exit(EXIT_FAILURE);
        }
        close(pipe_fd[1]);
	    dup2(pipe_fd[0], 0);
	    dup2(tmpFd, 1);
	    close(pipe_fd[0]);
	    close(tmpFd);
        if (execve(_argv[0], _argv, _env))
        {
			std::cerr << "Error: execve" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    write(pipe_fd[1], _requestPayload.c_str(), _requestPayload.length());
    close(pipe_fd[1]);
    close(pipe_fd[0]);   
    int status;
	if (waitpid(pid, &status, 0) == -1 || WEXITSTATUS(status) == EXIT_FAILURE)
	{
        return processErr("Error: CGI. ");
	}
    return true;
}

void    CGI::setCGIenv()
{
    std::map<std::string, std::string>  env;
    std::map<std::string, std::string>::iterator it;

    env["CONTENT_TYPE"] = _request->getHeaderValue("content-type:");
    env["CONTENT_LENGTH"] = utils::intToString(_requestPayload.length());
	env["GATEWAY_INTERFACE"] = "CGI/1.1";
	env["PATH_INFO"] = _request->getTargetPath();
	env["PATH_TRANSLATED"] = _fullPath;
	env["QUERY_STRING"] = _request->getQueryString(); 
	env["REMOTE_ADDR"] = _ip;
	env["REQUEST_METHOD"] = _request->getMethod();
	env["REQUEST_URI"] = _request->getTargetPath();
	env["SCRIPT_NAME"] = _cgiPath;
	env["SERVER_NAME"] = _request->getHeadersMap()["host:"];
	env["SERVER_PORT"] = utils::intToString(_port);
	env["SERVER_PROTOCOL"] = "HTTP/1.1";
	env["SERVER_SOFTWARE"] = "Webserver/1.0";
    if (_ext == "php")
		env["REDIRECT_STATUS"] = "200";
	if (!_auth.empty())
	{
        std::vector<std::string> creds = utils::split(_auth, ':');
        if (creds.size() == 2)
        {
		    env["REMOTE_IDENT"] = creds[0];
		    env["REMOTE_USER"] = creds[1];
        }
		env["AUTH_TYPE"] = "Basic";
	}

    /* HTTP HEADERS VALUES */
    std::map<std::string, std::string>  headers(_request->getHeadersMap());
	for (it = headers.begin(); it != headers.end(); it++)
	{
        std::string tmp = it->first;
        tmp.erase(tmp.find(":"));
		std::string name("HTTP_" + utils::stringToUpper(tmp));
		std::replace(name.begin(), name.end(), '-', '_');
		env[name] = it->second;
	}

	if (!(_env = (char **)malloc(sizeof(char *) * (env.size() + 1))))
    {
        std::cerr << "Error: malloc" << std::endl;
		return ;
    }
	int i = 0;
	for (it = env.begin(); it != env.end(); it++)
	{
		std::string tmp = it->first + "=" + it->second;
		_env[i++] = utils::ftStrdup(tmp.c_str());
	}
	_env[i] = NULL;
}

std::string CGI::translatePath()
{
    char            buf[256];
    std::string     translatedPath;

    getcwd(buf, sizeof(buf));
    translatedPath = buf + _resourcePath.erase(_resourcePath.find_first_of("."), 1);
    return translatedPath;
}

bool CGI::readFile(std::string file)
{
    int fd;
    std::string buffer;
    struct stat sb;

    buffer.clear();
    if ((fd = open(file.c_str(), O_RDONLY)) == -1)
        return processErr("Error: Open() has failed while opening CGI fd");
    fstat(fd, &sb);
    buffer.resize(sb.st_size);

    if (utils::readThroughSelect(fd) == -1)
        return processErr("Error: Read() Through Select has failed on CGI fd");
    if (read(fd, const_cast<char*>(buffer.data()), sb.st_size) == -1)
        return processErr("Error: Read() has failed on CGI fd");
    _cgiOutput = buffer;
    close(fd);
    return true;
}

void    CGI::parseHeaders(std::string &str, char delim)
{
	size_t start;
	size_t end = 0;
	size_t pos;
    std::string tmp;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
        tmp.clear();
		end = str.find(delim, start);
		tmp = str.substr(start, end - start);
        if ((pos = tmp.find(":")) != std::string::npos)
        {
            std::string name = tmp.substr(0, pos + 2);
            std::string value = tmp.substr(pos + 2, std::string::npos);
            _responseHeaders[name] = value;
        }
	}
}

void    CGI::parseOutput(void)
{
	std::string headersStr;
	size_t pos;
	size_t endline;

    if (!readFile(TMPFILE))
        return ;
    unlink(TMPFILE);
    _statusCode = 200;
	if ((pos = _cgiOutput.find("\r\n\r\n")) != std::string::npos)
    {
		headersStr = _cgiOutput.substr(0, pos);
        if ((pos + 4) >= _cgiOutput.size())
            _payload = _cgiOutput.substr(pos);
        else
            _payload = _cgiOutput.substr(pos + 4);
    }
    else
    {
        pos = 0;
	    _payload = _cgiOutput.substr(pos);
    }  
	if (!headersStr.empty())
	{
		if ((pos = _cgiOutput.find("Status:")) != std::string::npos)
        {
            endline = _cgiOutput.find("\n", pos);
            _statusCode = utils::stringToInt(_cgiOutput.substr((pos + 8), endline));
            headersStr.erase(pos, endline + 1);
        }
        parseHeaders(headersStr, '\n');
	}
}

int     CGI::getStatusCode(void)
{
    return _statusCode;
}

std::map<std::string,std::string>   CGI::getHeaders(void)
{
    return _responseHeaders;
}

std::string     CGI::getPayload(void)
{
    return _payload;
}

bool     CGI::processErr(std::string const &msg)
{
	std::cerr << msg << strerror(errno) << std::endl;
    _statusCode = 500;
	return false;
}

void    CGI::printEnv()
{
    std::cout << std::endl <<  "------CGI ENVIRONNEMENT VARIABLES -----------" << std::endl << std::endl;
    int i = 0;
    while (_env[i])
    {
        std::cout << _env[i++] << std::endl;
    }
    std::cout << std::endl << "----------------------------------------- END " << std::endl << std::endl;
}