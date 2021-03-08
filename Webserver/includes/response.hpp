#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <fstream>
# include <string>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>

# include "client.hpp"
# include "cgi.hpp"

# define DEFAULT_ERR_FILE "./www/html/errors/error.html"

class Response
{

/**
 * Class used to prepare a reponse to a request.
 */
private:

    ConfigServer                        _cfg;
    Request                             *_req;
    std::string                         _ip;
    int                                 _port;
    std::string                         _requestPayload;
    
    std::string                         _resourcePath;
    Location                            _locat;
    int                                 _responseCode;
    std::map<std::string, std::string>	_responseHeaders;
    std::string                         _responseBody;

    std::map<int, std::string>          _statusCodeMap;

public:

    Response();
    Response(Client *c, std::map<int, std::string> statusCodeMap);
    ~Response();

    /**
     * Dispatch to the corresponding method handler if the request is compliant with the config requirements.
     * Else set the error code and switch to error handling.
     */
    void        executeMethod(void);

    /**
     * Fetch the representation of the corresponding error code and add it to the response buffer.
     */
    void        createErrorMsg(void);

    /**
     * Execute CGI based on uri extension and parse the output into the response payload.
     */
    void        handleCgi(void);

    /**
     * Handler for the GET method.
     */
    void        handleGet(void);

    /**
     * Handler for the HEAD method.
     */
    void        handleHead(void);

    /**
     * Handler for the POST method.
     */
    void        handlePost(void);

    /**
     * Handler for the PUT method.
     */
    void        handlePut(void);

    /**
     * Handler for the unavailable errors.
     */
    void        handleUnavailable(void);

    /**
     * Get the location block corrsponding to the target URI in the config.
     */
    Location    findLocation(ConfigServer &conf, std::string targetPath);

    /**
     * Translate the target URI path into the resource path according to config's root directive.
     */
    std::string createPath(void);

    /**
     * Return false if the request payload is superior to the max body size set in the config.
     * If no max body size data in config, there will be no limit by default.
     */
    bool        checkMaxBodySize(void);

    /**
     * Return false if data in the request headers do not match the credentials in the config.
     */
    bool        checkAuthorization(void);

    /**
     * Return false if the requested method is not part of the list of implemented methods by the server.
     */
    bool   	    checkMethod(void);

    /**
     * Return true if the uri extension match the one in the config file.
     */
    bool        hasCGIext(std::string const &targetPath, std::string const &confCGIExt);

    /**
     * Helper function to add specific error code messages to a default error representation.
     */
    void        customizeErrorResponse(void);

    /**
     * If index directive in the config.
     * Look for the best index represention to send as a response.
     */
    bool        handleIndex(void);

    /**
     * If autoindex directive in the config.
     * Generate a html index page if autoindex in on.
     * Create 404 (Not Found) error message if off.
     */
    void        autoIndex(std::string const &targetPath);

    /**
     * Analyze a representation to serve the version of the resource best fit for the request.
     */
    std::vector<std::string>  contentNegociation(std::vector<std::string> index, std::string path);

    /**
     * Content Negociation Helper function. Get the language and charset details of each valid representation.
     */
    std::vector<std::string>  createContentsList(std::vector<std::string> acceptLang, std::vector<std::string> index, std::string path, std::string word);
    
    /**
     * POST and PUT handlers helper function. Add to or create a ressource representation.
     */
    void        writeInFile(int fd);

    /**
     * Setter functions. Parse the request buffer before storing into variable. 
     */
    void        setResponseBody(std::string file);
    void        setResponseHeaders(void);


    /**
     * Getter functions.
     */
    int                                 getResponseCode(void);
    std::map<std::string, std::string>  getResponseHeaders(void);
    std::string                         getResponseBody(void);

};

#endif