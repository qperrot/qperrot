#ifndef UTILS_HPP
# define UTILS_HPP

# include <vector>
# include <map>
# include <time.h> 
# include <iostream>  
# include <fstream> 
# include <algorithm> 
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <cstdlib>

# define MIME "./mime.types"

# define SECS_PER_YEAR 31556926
# define SECS_PER_MONTH 2629743
# define SECS_PER_DAY 86400
# define SECS_PER_HOUR 3600
# define SECS_PER_MIN 60

#define WHITESPACE " \t\f\v\n\r"

#define IS_MAJ(x)	( ((x) >= 'A' && (x) <= 'Z') ? true : false )
#define IS_MIN(x)	( ((x) >= 'a' && (x) <= 'z') ? true : false )

#define IS_MAJ_HEXA(x) ( ((x) >= 'A' && (x) <= 'F') ? true : false )
#define TO_MAJ(x) ( ((x) >= 'a' && (x) <= 'f') ? (x - 32) : x )
#define IS_DIGIT(x) ( ((x) >= '0' && (x) <= '9') ? true : false )
#define IS_MIN_hexa(x) ( ((x) >= 'a' && (x) <= 'f') ? true : false )

namespace utils
{

/*******************************************************************/
/******************     LIBFT FUNCTIONS UTILS    *******************/
/*******************************************************************/

void    ftBzero(void *s, size_t n);
int     ftStrlen(const char *str);
char    *ftStrdup(const char *str);
void    freeTab(char **tab);
std::vector<std::string>    split(std::string line, char c);


/*******************************************************************/
/******************    STRING FUNCTIONS UTILS    *******************/
/*******************************************************************/

size_t          stringToInt(std::string str);
std::string     intToString(int n);
std::string	    stringTolower(std::string str);
std::string		stringToUpper(std::string str);
std::string     eraseOWS(std::string str);
char            back(std::string str);


/*******************************************************************/
/******************     TIME FUNCTIONS UTILS     *******************/
/*******************************************************************/

time_t	    getTime();


/*******************************************************************/
/******************    HEADERS FUNCTIONS UTILS   *******************/
/*******************************************************************/

bool            hasHeader(std::string const &name, std::map<std::string, std::string> &headerMap);
std::string     dateHeader(void);
std::string     lastModifiedHeader(std::string const &file);
std::string     getWeight(const std::string &str);
bool            compareWeight(const std::string& first, const std::string& second);
std::vector<std::string>    parseByWeight(std::string headerValue);
std::string     findLangAndCharset(std::string word, std::string tmp);
std::map<std::string, std::string>    parseMime(void);


/*******************************************************************/
/******************    DECODE FUNCTIONS UTILS    *******************/
/*******************************************************************/

static const std::string base64Chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

static const std::string hex_chars =
             "0123456789ABCDEF";

static inline bool  isBase64(unsigned char c);
std::string         base64Decode(std::string const& encoded_string);
std::string         convertHex(std::string str);
long                hexaToLong(std::string hex);


/*******************************************************************/
/******************    SELECT FUNCTIONS UTILS    *******************/
/*******************************************************************/

int     writeThroughSelect(int fd);
int     readThroughSelect(int fd);

}; // end namespace utils

#endif