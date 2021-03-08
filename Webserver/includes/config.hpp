#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <map>
# include <vector>
# include <string>
# include <iostream>
# include <exception>

# include "location.hpp"

# define OK_GOOD 1
# define ERR_PORT 0

class ConfigServer
{

/**
 * Class storing the config data for a single server.
 */

private:

    int                         _listen;
    std::string                 _host;
    std::vector<std::string>    _serverName;
    std::map<int, std::string>  _errorPage;
    std::vector<Location>       _routesCfg;

public:

    ConfigServer();
    ConfigServer &operator=(ConfigServer const &other);
    ~ConfigServer();

    /**
     * Setter functions. Parse the received buffer before storing into variable. 
     * Will throw exception if any error
     */

    void    setListen(std::string &buffer);
    void    setHost(std::string &buffer);
    void    setServerName(std::string &buffer);
    void    setErrPage(std::string &buffer);
    void    setLocation(Location &location);

    /**
     * Getter functions.
     */

    int                         getListen(void);
    std::string                 getHost(void);
    std::vector<std::string>    getServerName(void);
    std::map<int, std::string>  getErrorPage(void);
    std::vector<Location>       getRoutes(void);

    /**
     * Check whether the config is valid.
     */
    int     checkIfValid(void);

    /**
     * Set all members value to zero.
     */
    void    reset();

    /**
     * Returns whether the config is empty.
     */
    bool    empty();

    /**
     * Debug function.
     */
    void    print();
};

#endif