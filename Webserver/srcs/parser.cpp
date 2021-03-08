# include "parser.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

void    Parser::load(std::string const &file)
{
	std::ifstream	in(file.c_str());
	if (in.fail())
    {
        throw std::runtime_error("Failed to open file " + file + " for reading.");
    }
	parse(in);
	in.close();
}

void    Parser::parse(std::istream &i)
{
    _input = &i;
    _currentToken = tokenize();
    while (_currentToken != FILE_END)
    {
        if (_currentToken == SERVER)
        {
            parseServerBlock();
            // _config.print(); // debug
            _cfgList.push_back(_config);
        }
        getNextToken();
    }
    if (_cfgList.empty())
        throw std::runtime_error("Config invalid: cannot be empty");
    int check;
    if ((check = checkValidCfgs()) != OK_GOOD)
    {
        if (check == ERR_PORT)
            throw std::runtime_error("Config invalid: port must be present in each config");
        if (check == ERR_NAMES)
            throw std::runtime_error("Config invalid: server names cannot be identical");
    }
}

Parser::Token    Parser::getNextToken(void)
{
    if (_currentToken != FILE_END)
    {
        _currentToken = tokenize();
    }
    return _currentToken;
}

bool	Parser::isDirective(std::string token)
{
    std::string directives[DIRECTIVES_NBR] = {"listen", "root", "server_name", "error_page",
        "client_max_body_size", "limit_except", "index", "autoindex", "cgi", "auth_basic",
        "upload_folder", "host"};

    for (int i = 0; i < DIRECTIVES_NBR; i++)
    {
        if (token == directives[i])
            return true;
    }
    return false;
}

Parser::Token   Parser::tokenize(void)
{
    std::istream& input = *_input;	
    _tokenBuffer.clear();
    char c = input.get();

    if (c == EOF)
        return FILE_END;
    if (c == ';')
    {
        _tokenBuffer = c;
        return SEMICOLON;
    }
    // Skip whitespaces.
    while (isspace(c))
        c = input.get();

    // get token identifiers
    while (c != EOF && !isspace(c))
    {
        if (c == ';')
        {
            input.unget();
            return PARAMETER;
        }
        _tokenBuffer += c;
        c = input.get();
    }
    if (_tokenBuffer == "server")
        return SERVER;
    if (_tokenBuffer == "location")
        return LOCATION;
    if (_tokenBuffer == "{")
        return OPEN_BRACKET;
    if (_tokenBuffer == "}")
        return CLOSE_BRACKET;
    if (isDirective(_tokenBuffer))
        return DIRECTIVE;

    return PARAMETER;
}

void    Parser::parseServerBlock(void)
{
    bool    block_open;

    directiveStruct<ConfigServer>  servDir[SERV_DIR_NBR] = {
        {"listen", &ConfigServer::setListen},
        {"host", &ConfigServer::setHost},
        {"server_name", &ConfigServer::setServerName},
        {"error_page", &ConfigServer::setErrPage}
    };

    checkOpenBracket();
	_config.reset();
    block_open = 1;
    while (block_open)
    {
        getNextToken();
        if (_currentToken == DIRECTIVE)
        {
            handleDirective(_config, servDir, SERV_DIR_NBR); 
        }
        else if (_currentToken == LOCATION)
        {
            parseLocationBlock();
        }
        else if (_currentToken == CLOSE_BRACKET)
        {
            block_open = 0;
        }
        else
        {
            if (_currentToken == SERVER || _currentToken == FILE_END)
                throw std::runtime_error("Syntax error: missing closing bracket in server block");
            else
                throw std::runtime_error("Syntax error: non-existing directive in server block");
        }
    }
}

void    Parser::parseLocationBlock(void)
{
    Location    locationBlock;

    directiveStruct<Location>   locationDir[LOCAT_DIR_NBR] = {
        {"root", &Location::setRoot},
        {"limit_except", &Location::setMethod},
        {"index", &Location::setIndex},
        {"cgi", &Location::setCgi},
        {"autoindex", &Location::setAutoindex},
        {"auth_basic", &Location::setAuth},
        {"client_max_body_size", &Location::setMaxBodySize},
        {"upload_folder", &Location::setUploadPath},
    };

    getNextToken();
    locationBlock.setURI(_tokenBuffer);
    checkOpenBracket();
    while (_currentToken != CLOSE_BRACKET)
    {
        getNextToken();
        if (_currentToken == DIRECTIVE)
        {
            handleDirective(locationBlock, locationDir, LOCAT_DIR_NBR);
        }
        else if (_currentToken != CLOSE_BRACKET)
        {
            if (_currentToken == LOCATION || _currentToken == FILE_END)
                throw std::runtime_error("Syntax error: missing closing bracket in location block");
            else
                throw std::runtime_error("Syntax error: non-existing directive in location block");
        }
    }
    _config.setLocation(locationBlock);
}

void    Parser::checkOpenBracket(void)
{
    if (getNextToken() != OPEN_BRACKET)
    {
        throw std::runtime_error("Syntax error: missing open bracket");
    }
}

template<class T>
void    Parser::handleDirective(T &obj, directiveStruct<T> dirArray[], int size)
{
    std::string directiveName;
    std::string paramBuffer;

    directiveName = _tokenBuffer;
	while (getNextToken() == PARAMETER && _currentToken != FILE_END)
    {
        if (!_tokenBuffer.empty())
    	    paramBuffer += _tokenBuffer + " ";
    }
    if (paramBuffer.empty())
        throw std::runtime_error("Syntax error: directive must have at least one parameter");
    // execute the function related to the directive
    for (int i = 0; i < size; i++)
    {
        if (!dirArray[i].dirName.empty() && dirArray[i].dirName == directiveName)
        {
            (obj.*(dirArray[i].f))(paramBuffer);
            break ;
        }
    }
    if (_currentToken != SEMICOLON)
    {
        throw std::runtime_error("Syntax error: missing semicolon at the end of directive");
    }
}

int    Parser::checkValidCfgs(void)
{
    std::vector<std::string> allServerNames;
    std::vector<std::string>::iterator name;
    for (std::vector<ConfigServer>::iterator cfg = _cfgList.begin(); cfg != _cfgList.end(); cfg++)
    {
        if (cfg->checkIfValid() != OK_GOOD)
            return ERR_PORT;
        std::vector<std::string> cfgNames = cfg->getServerName();
        for (name = allServerNames.begin(); name != allServerNames.end(); name++)
        {
            if (std::search_n(cfgNames.begin(), cfgNames.end(), 1, *name) != cfgNames.end())
                return ERR_NAMES;
        }
        allServerNames.insert(allServerNames.end(), cfgNames.begin(), cfgNames.end());
    }
    return OK_GOOD;
}

std::vector<ConfigServer>   Parser::getCfgList(void)
{
    return _cfgList;
}