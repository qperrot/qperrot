#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <errno.h>

# include "config.hpp"
# include "request.hpp"
# include "enum.hpp"

# define BUFSIZE 8192

class Client
{

/**
 * Class used to handle each client connection. 
 * Keeps data about each clent (ip, port, socket it is connected to)
 * Receive request into bufferIn and send response via bufferOut.
 */
private:

    int                         _sockFd;
    int                         _port;
    std::string                 _ip;
    int                         _bytesRead;
    int                         _bytesSent;
    std::string                 _bufferIn;
    std::string                 _bufferOut;
    size_t                      _offset;
    std::vector<ConfigServer>   _cfgList;
    Request                     *_req;
    e_readState                 _state;
    time_t                      _timeLastRecv;

public:

    Client();

    /**
     * Create a client by assigning the socket it is connected to.
     * Retrieve all client info.
     */
    Client(int socket);

    /**
     * Destroy the client object and delete the request object if not empty.
     */
    ~Client();

    /**
     * Get data from the socket and add it into the bufferIn.
     */
    int     receiveReq(int connection);

    /**
     * Send data from bufferOut into the socket.
     */
    int     sendResponse();
 
    /**
     * Check if the totality of the request has been received.
     */
    bool    isDoneRecv();

    /**
     * Check whether the client has been inactive for more than the set timeout value.
     */
    bool    checkTimeout(time_t time);

    /**
     * Reset timeout counter everytime there is an activity on the client end.
     */
    void    resetTimeout();

    /**
     * Create and allocate memory for a new Request object.
     */
    void            initRequest(void);

    /**
     * Getter functions.
     */
    int                         getSocket();
    int                         getPort();
    std::string                 getIp();
    Request                     *getRequest();
    std::vector<ConfigServer>   getConfigList();
    e_readState                 getState();
    std::string                 getBufIn();
    std::string                 getBufOut();

    /**
     * Setter functions.
     */
    void            setConfig(std::vector<ConfigServer> cfgs);
    void            setState(e_readState const &state);
    void            setBufOutput(std::string const &response);
};

#endif