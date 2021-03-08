#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>
# include <cctype>
# include <exception>
# include <sys/stat.h> 
# include <fcntl.h>
# include <unistd.h>

# include "config.hpp"
# include "location.hpp"

# define    DIRECTIVES_NBR 12
# define    SERV_DIR_NBR 4
# define    LOCAT_DIR_NBR 8

# define    ERR_NAMES 2

class ConfigServer;
class Location;

class Parser
{

/**
 * Class used to parse the server's config file.
 */

private:

    enum Token
    {
        NO_TOKEN,
	    SEMICOLON,
	    OPEN_BRACKET,
	    CLOSE_BRACKET,
	    SERVER,
	    LOCATION,
        DIRECTIVE,
        PARAMETER,
        FILE_END,
    };

    template<class T>
    struct directiveStruct
    {
        std::string     dirName;
        void            (T::*f)(std::string &buffer);
    };

	std::istream	            *_input;
	Token 			            _currentToken;
	std::string		            _tokenBuffer;
	ConfigServer	            _config;
    std::vector<ConfigServer>   _cfgList;

public:

    Parser();
    ~Parser();

    /**
     * Read the file into string and send it to the parser
     */

    void    load(std::string const &file);

    /**
     * Main parsing loop
     */
    void    parse(std::istream &i);

    /**
     * Separate words into tokens
     */
	Token   tokenize(void);

    /**
     * Returns the token next to the current one
     */
    Token	getNextToken(void);

    /**
     * Is part of the implemented config directives
     */
	bool	isDirective(std::string token);

    /**
     * Extract each server block and parse each token into the members of the ConfigServer class
     */
	void	parseServerBlock(void);

    /**
     * Extract each location blocks and parses its info
     */
	void	parseLocationBlock(void);

    /**
     * Parsing helper function. Match the token to its handling function
     */
    template<class T>
    void    handleDirective(T &obj, directiveStruct<T> dirArray[], int size);

    /**
     * Parsing helper function. Check whether we have entered a block (server or location)
     */
    void    checkOpenBracket(void);

    /**
     * Checks if the server config is valid by checking the value of host and listen
     */
    int     checkValidCfgs(void);

    /**
     * Returns the list of all the parsed server configs present in the config file
     */
    std::vector<ConfigServer>   getCfgList(void);

};

#endif