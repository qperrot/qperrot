#ifndef SERVER_HPP
# define SERVER_HPP

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <cstdlib>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <iostream>
# include <vector>
# include <list>
# include <queue>
# include <map>
# include <cstring>
# include <algorithm>

# include "parser.hpp"
# include "client.hpp"
# include "request.hpp"
# include "response.hpp"
# include "log.hpp"

# define BACKLOG 128
# define MAX_CONNECTIONS 255

static bool     isRunning = true;

class HTTPServer
{

/**
 * Class used as the main orchestrator of the HTTP/1.1 protocol.
 * Take care of the communication between each server and each client.
 */
private:

    Parser                      _cfgParser;
    std::vector<ConfigServer>   _servCfg;
    std::vector<int>            _sockets;
    std::list<Client*>          _clientList;

    std::vector<std::string>    _implementedMethods;
    std::map<int, std::string>  _statusCodeMap;

public:

    fd_set              readMaster;
    fd_set              writeMaster;
    std::list<int>      sdList;

    HTTPServer();
    ~HTTPServer();

    /**
     * Get the servers data from the config file.
     */
    void                loadConfig(std::string const &confFile);

    /**
     * Send all servers in the config for setup.
     */
    void                initServers(void);

    /**
     * Open a TCP connection for a server on the requested host and port.
     */
    void                setupTCP(int port, std::string const &host);

    /**
     * Prepare the write and read FD sets for the main loop.
     * Add all the servers listening sockets to the read FD set.
     */
    void                initFdSets(void);

    /**
     * Accept an incomming connection on the server listening socket.
     */
    void                acceptNewConnection(int listen_sd);

    /**
     * Orchestrate the request handling and parsing.
     * Modify the receiving state according to each function return.
     */
    void                handleRequest(Client *c);

    /**
     * Orchestrate the response handling.
     * Fill the client's output buffer with the generaated response.
     */
    int                 handleResponse(Client *c);

    /**
     * Generate a HTTP/1.1 response with all the data present in Response object.
     */
    std::string         generateResponse(Response *r, std::string const &method);

    /**
     * Delete client object, remove it from FD sets, and close its connection socket.
     */
    void                cleanConnection(Client *c);

    /**
     * Return all the server configs that match the host:port pair.
     */
    std::vector<ConfigServer>   matchServerCfgs(int port, std::string const &host);

    /**
     * Return the client object corresponding to the connected socket.
     */
    Client                      *matchClient(int connection);

    /**
     * Getter functions.
     */
    std::vector<int>    getSockets(void);
    std::list<Client*>  getClientList(void);
};


#endif
