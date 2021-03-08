#ifndef CGI_HPP
#define CGI_HPP

# include <map>
# include <vector>
# include <string>
# include <iostream>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>

# include "config.hpp"
# include "request.hpp"

#define TMPFILE "./tmpfile"

/* Meta-Variables (env)

AUTH_TYPE           : Basic
CONTENT_LENGTH      : size of the message-body attached to the request
CONTENT_TYPE        : MIME type of the request body
GATEWAY_INTERFACE   : La révision de la spécification CGI que le serveur utilise. (Format : CGI/révision)
PATH_INFO           : relative path to target file
PATH_TRANSLATED     : translation from virtual path to physical path in local machine
QUERY_STRING        : everything after the ? in the uri
REMOTE_ADDR         : the IP address of the visitor
REMOTE_IDENT        : identity information about user agent
REMOTE_USER         : the username the user has authenticated as
REQUEST_METHOD      : GET or POST
REQUEST_URI         : uri
SCRIPT_NAME         : cgi script path
SERVER_NAME         : Le nom d'hôte, alias DNS ou adresse IP du serveur.
SERVER_PORT         : TCP/IP port number on which this request is received from the client
SERVER_PROTOCOL     : HTTP/1.1
SERVER_SOFTWARE     : Le nom et la version du serveur répondant à la requête. (Format : nom/version)

*/

class CGI
{

    /**
     * Class used to process all cgi requests.
     */

private:

    Request         *_request;
    Location        _locat;
    std::string     _cgiPath;
    std::string     _ext;
    std::string     _resourcePath;
    std::string     _requestPayload;
    int             _port;
    std::string     _ip;
    std::string     _auth;
    std::string     _fullPath;

    char                                **_env;
    char                                **_argv;
    std::string                         _cgiOutput;
    int                                 _statusCode;
    std::map<std::string,std::string>   _responseHeaders;
    std::string                         _payload;

    CGI();

public:

    /**
     * Construct the CGI class with metadata variables info
     */
    CGI(Request *req, Location locat, std::string &path, std::string &payload, int port, std::string &ip);
    
    /**
     * Destructor.
     */
    ~CGI();

    /**
     * Execute the CGI script and write the result in TMPFILE.
     */
    bool        execCGI();

    /**
     * Set the environnement variables for the CGI script. Populates char env for the execve.
     */
    void        setCGIenv();

    /**
     * Translate the resource path from virtual to physical file system path
     */
    std::string translatePath();

    /**
     * Parse the CGI output and extract Status Code, Headers and Payload
     */
    void        parseOutput(void);

    /**
     * ParseOuptput Helper function. Read the contents of TMPFILE and put it in cgiOutput
     */
    bool        readFile(std::string file);

    /**
     * ParseOuptput Helper function. Extract all the headers
     */
    void        parseHeaders(std::string &str, char delim);

    /**
     * Return the appropriate error message
     */
    bool        processErr(std::string const &msg);

    /**
     * Return the CGI status code
     */
    int         getStatusCode(void);

    /**
     * Return the CGI headers
     */
    std::map<std::string,std::string>   getHeaders(void);

    /**
     * Return the CGI payload
     */
    std::string getPayload(void);

    /**
     * Debug function
     */
    void        printEnv();

};

#endif
