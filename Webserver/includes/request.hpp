#ifndef REQUEST_HPP
# define REQUEST_HPP

#include <string>
#include <vector>
#include <map>

# include "config.hpp"
# include "enum.hpp"
# include "utils.hpp"

# define MAX_URI_LEN 10000

class Request
{

/**
 * Class used to process and parse a request.
 */
private:

	std::string							_startLine;
	std::string							_method;
	std::string							_requestUri;
	std::string							_version;
	std::map<std::string, std::string>	_headersMap;
	std::string							_requestPayload;
	std::string							_targetPath;
	std::string							_queryString;
    ConfigServer                        _cfg;
	int									_statusCode;

public:

    Request();
    Request(Request const &other);
    ~Request();

    /**
     * Parse the request start line. Will return the state :
     *  - Start line if the line has not been completely received
     *  - Header if the start line is complete and correct
     *  - Error for any error in the line
     */
    e_readState     parseStartLine(std::string &requestBuf, std::vector<std::string> &implementedMethods);
    
    /**
     * Parse the request headers. Will return the state :
     *  - Header if the headers have not been completely received
     *  - Complete if the start line is complete, correct and no body is expected
     *  - Body if there is either a Transfer-Encoding or Content-Length header
     *  - Error for any error in the headers
     */
    e_readState     parseHeaders(std::string &requestBuf, std::vector<ConfigServer> cfgList);

    /**
     * Parse the request payload. Will return the state :
     *  - Body if the paylooad has not been completely received
     *  - Complete if the payload is complete and correct
     *  - Error for any error in the payload
     */
    e_readState     parsePayload(std::string &requestBuf);

    /**
     * Return false and set the corresponding status code if the method is not RFC compliant.
     * A server that receives a method longer than any that it implements SHOULD respond 
     * with a 501 (Not Implemented) status code.
     */
    bool            checkMethod(std::vector<std::string> &implementedMethods);

    /**
     * Return false and set the corresponding status code if the Uri is not RFC compliant.
     * Check the max len and the syntax of the Uri.
     */
    bool            checkUri(void);

     /**
     * Return false and set the corresponding status code if the version .
     * is not equal to "HTTP/1.1".
     */
    bool            checkVersion(void);

    /**
     * Parse the headers into a map First = headers's name, Second = headers's value.
     * Return false and set the status code to 400 (Bad request) if a header is present more than once.
     */
    bool            parseToMap(std::string &headerStr);

    /**
     * Check the syntax of the headers.
     * Return false and set the corresponding status code if the syntax is not rfc compliant.
     */
    bool            checkHeaders(void);

    /**
     * Look for the corresponding config by server name in the list of all configs with 
     * the same host:port pairs.
     * Return the matched config or the first config in the list by default if no match is found.
     */
    ConfigServer    getCorrectConfig(std::vector<ConfigServer> cfgList);

    /**
     * Decode the payload of a chunked request.
     * Return false and set the corresponding status code if the chunked syntax is wrong.
     */
    bool            decodeChunkedBody(void);

    /**
     * Getter functions.
     */
    std::string                         getStartLine(void);
    int                                 getStatusCode(void);
    std::map<std::string, std::string>  getHeadersMap(void);
    std::string                         getTargetPath(void);
    std::string                         getQueryString(void);
    std::string                         getMethod(void);
    std::string                         getVersion(void);
    std::string                         getPayload(void);
    std::string                         getHeaderValue(std::string const &headerName) const;
    ConfigServer                        getConfig(void);

    /**
     * Debug function.
     */
    void    printRequest(void);
};

#endif