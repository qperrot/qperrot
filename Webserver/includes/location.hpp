#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <map>
# include <vector>
# include <string>
# include <iostream>

# include "utils.hpp"

class Location
{

/**
 * Class used to parse the location blocks in each config.
 */

private:

    std::string                         _requestURI;
    std::string                         _root;
    std::vector<std::string>            _methods;
    std::string                         _index;
    std::map<std::string, std::string>  _cgi;
    std::string                         _auth;
    bool                                _autoindex;
    int                                 _clientMaxBodySize;
    std::string                         _uploadPath;
    bool                                _hasBodySize;

public:

    Location();
    Location(Location const &other);
    Location &operator=(Location const &other);
    ~Location();

    /**
     * Setter functions. Parse the received buffer before storing into variable. 
     * Will throw exception if any error
     */

    void    setURI(std::string &buffer);
    void    setRoot(std::string &buffer);
    void    setMethod(std::string &buffer);
    void    setIndex(std::string &buffer);
    void    setCgi(std::string &buffer);
    void    setAutoindex(std::string &buffer);
    void    setAuth(std::string &buffer);
    void    setMaxBodySize(std::string &buffer);
    void    setUploadPath(std::string &buffer);

    /**
     * Getter functions.
     */
    std::string                         getUri(void) const;
    std::string                         getRoot(void) const;
    std::vector<std::string>            getMethod(void) const;
    std::string                         getIndex(void) const;
    bool                                getAutoindex(void) const;
    std::string                         getAuth(void) const;
    int                                 getClientMaxBodySize(void) const;
    std::string                         getUploadPath(void);
    std::map<std::string, std::string>  getCgi(void) const;

    /**
     * Debug function.
     */
    void    printLocation(void);
};

#endif