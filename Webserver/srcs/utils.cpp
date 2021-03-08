# include "utils.hpp"

namespace utils
{

/*******************************************************************/
/******************     LIBFT FUNCTIONS UTILS    *******************/
/*******************************************************************/

void    ftBzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int     ftStrlen(const char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

char    *ftStrdup(const char *str)
{
	char *ret;
	int i = 0;

    if (!(ret = (char *)malloc(ftStrlen(str) + 1)))
    	return NULL;
    while (str[i])
    {
    	ret[i] = str[i];
    	i++;
    }
    ret[i] = '\0';
    return ret;
}

void    freeTab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
    free(tab);
    tab = NULL;
}

std::vector<std::string>    split(std::string line, char c)
{
    std::vector<std::string> list;
    std::string tmp;
    std::size_t found = line.find("\r\n");
    if (found == std::string::npos)
        found = line.size();
    size_t i = 0;
    while(i < found)
    {
        if (i == 0 && line[i] == c)
            return list;
        else if (line[i] != c)
        {
            tmp.push_back(line[i]);
            i++;
        }
        else
        {
            if (!tmp.empty())
            {
                list.push_back(tmp);
                tmp.clear();
            }
            while (i < found && line[i] == c)
                i++;
        }
    }
    if (!tmp.empty())
    {
        list.push_back(tmp);
        tmp.clear();
    }
    return list;
}


/*******************************************************************/
/******************    STRING FUNCTIONS UTILS    *******************/
/*******************************************************************/

size_t          stringToInt(std::string str)
{
    int result = 0;
    size_t i = 0;
        
    if (str.substr(0, 12) == "-2147483648" && (str.size() == 12 || !isdigit(str[12])))
	    return -2147483648;

    if (str[0] == '+' || str[0] == '-' ) 
         ++i;
    while (i < str.size())
    {
        if (str[i] >= '0' && str[i] <= '9' )
        {
           int value = (str[0] == '-') ? ('0' - str[i] ) : (str[i] - '0');
           result = result * 10 + value;
        }
        else
           break;
        i++;
    }
    return result;
}

std::string     intToString(int n)
{
    std::string s_num;
    char        c;
    int		    i;
	long	    nb;
	long	    div;
	long	    num;

	div = 1;
	nb = 0;
	i = 0;
	num = (long)n;
	if (n < 0)
		num *= -1;
	nb = num;
	if (nb < 10)
		i++;
	while (nb >= 10)
	{
		nb = num / div;
		div *= 10;
		i++;
	}
    if (n < 0)
		s_num = s_num + '-';
    nb = num;
    if (nb >= 10)
		div /= 10;
    while (div > 0)
	{
		nb = num / div;
		nb = nb % 10;
        c = nb + '0';
		s_num = s_num + c;
		div /= 10;
	}
	return (s_num);
}

std::string	    stringTolower(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (IS_MAJ(str[i]))
			str[i] = str[i] + 32;
	}
	return str;
	
}

std::string		stringToUpper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (IS_MIN(str[i]))
			str[i] = str[i] - 32;
	}
	return str;
	
}

std::string     eraseOWS(std::string str)
{
    std::string ret(str);
    size_t found ;

    found = ret.find_first_not_of(WHITESPACE);
    if (found != std::string::npos)
        ret.erase(0, found);
    found = ret.find_last_not_of(WHITESPACE);
    if (found != std::string::npos)
        ret.erase(found + 1);
    return ret;
}

char            back(std::string str)
{
    int i = 0;
    if (str.length() > 0)
    {
        i = str.length() - 1;
        return str[i];
    }
    return '\0';
}


/*******************************************************************/
/******************     TIME FUNCTIONS UTILS     *******************/
/*******************************************************************/

time_t	    getTime()
{
	struct timeval tv = {};

	gettimeofday(&tv, NULL);
	return (tv.tv_sec);
}


/*******************************************************************/
/******************    HEADERS FUNCTIONS UTILS   *******************/
/*******************************************************************/

bool            hasHeader(std::string const &name, std::map<std::string, std::string> &headerMap)
{
    std::map<std::string, std::string>::iterator it;
    for (it = headerMap.begin(); it != headerMap.end(); it++)
    {
        if (it->first == name)
            return true;
    }
    return false;
}

std::string     dateHeader(void)
{
    struct timeval tv;
    char date[128]= {0};
    gettimeofday(&tv, NULL);
    struct tm *ptm = gmtime(&tv.tv_sec);

    strftime(date, 64, "%a, %d %h %Y %H:%M:%S GMT", ptm);
    return (std::string)date;
}

std::string     lastModifiedHeader(std::string const &file)
{
    char date[128]= {0};
    struct stat buffer;
	if (stat(file.c_str(), &buffer) == 0)
    {
        struct tm *ptm = gmtime(&buffer.st_mtime);
        strftime(date, 64, "%a, %d %h %Y %H:%M:%S GMT", ptm);
        return (std::string)date;
    }
    else
        return (std::string)date;
}

std::string     getWeight(const std::string &str)
{
    size_t weightPos;

    if ((weightPos = str.find("q=")) != std::string::npos)
    {
        return (str.substr(weightPos + 2, std::string::npos));
    }
    else
        return ("1");
}

bool            compareWeight(const std::string& first, const std::string& second)
{
    return getWeight(first) > getWeight(second);
}

std::vector<std::string>    parseByWeight(std::string headerValue)
{
    std::vector<std::string>  tokens;
    std::vector<std::string>  ret;
    std::vector<std::string>::iterator it;

    std::remove_if(headerValue.begin(), headerValue.end(), isspace);
    tokens = utils::split(headerValue, ',');
    std::sort(tokens.begin(), tokens.end(), compareWeight);
    for (it = tokens.begin(); it != tokens.end(); it++)
    {
        ret.push_back(it->substr(0, it->find(";")));
    }
    return ret;
}

std::string     findLangAndCharset(std::string word, std::string tmp)
{
    std::string langCharset;
    if (tmp.find(word) != std::string::npos)
    {
        std::size_t found = tmp.find(word) + word.size();
        if (tmp[found] == '=')
            found++;
        else
            return langCharset;
        if (tmp[found] == '\"')
            found++;
        else
            return langCharset;
        std::string langTMP(tmp, found, tmp.size());
        for (size_t i = 0; i < langTMP.size(); i++)
        {
            if (langTMP[i] != '\"')
                langCharset.push_back(langTMP[i]);
            else
               return langCharset;
        }
    }
    return langCharset;
}

std::map<std::string, std::string>    parseMime(void)
{
    std::string tmp;
    std::map<std::string, std::string> mime_type;
    mime_type.clear();
    std::ifstream ifs(MIME);
    if (ifs.bad())
    {
        throw std::runtime_error("Failed to open " + std::string(MIME) + " for reading.");
    }
    std::istream &input = ifs;
    std::vector<std::string> tmp_vect;
    while (std::getline(input, tmp))
    {
        size_t found = tmp.find(";");
        if (found != std::string::npos)
            tmp = tmp.substr(0, found);
        else
            continue;
        tmp_vect = utils::split(tmp, ' ');
        if (tmp_vect.size() >= 2)
        {
            for (size_t i = 1; i < tmp_vect.size(); i++)
                mime_type.insert(std::pair<std::string,std::string>(tmp_vect[i],tmp_vect[0]));
        }
        tmp_vect.clear();
        tmp.clear();
    }
    ifs.close();
    return mime_type;
}


/*******************************************************************/
/******************    DECODE FUNCTIONS UTILS    *******************/
/*******************************************************************/

static inline bool isBase64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64Decode(std::string const& encoded_string)
{
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && isBase64(encoded_string[in_]))
  {
    char_array_4[i++] = encoded_string[in_]; 
    in_++;
    if (i == 4) {
      for (i = 0; i < 4; i++)
        char_array_4[i] = base64Chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j < 4; j++)
      char_array_4[j] = 0;

    for (j = 0; j < 4; j++)
      char_array_4[j] = base64Chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }
  return ret;
}

std::string convertHex(std::string str)
{
    std::string newstr;
    newstr.reserve(str.size());
    // str = stringToUpper(str);
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '%')
        {
            if ((i+1) < str.size() && hex_chars.find(TO_MAJ(str[i + 1])) != std::string::npos)
            {
                char a = TO_MAJ(str[i + 1]);
                if ((i+2) < str.size() && hex_chars.find(TO_MAJ(str[i + 2])) != std::string::npos)
                {
                    char b = TO_MAJ(str[i + 2]);
                    char decode = hex_chars.find(a) * 16 + hex_chars.find(b);
                    newstr.push_back(decode);
                    i += 2;
                }
            }
        }
        else
            newstr.push_back(str[i]);
    }
    return newstr;
}

long        hexaToLong(std::string hex)
{
    size_t i = 0;
    long dec = 0;
    long temp = 0;

    while (i < hex.size() && (hex[i] != '\r' && hex[i] != '\n'))
    {
        if (IS_MAJ_HEXA(hex[i]))
        {
            temp = hex[i] - 'A' + 10;
        }
        else if (IS_MIN_hexa(hex[i]))
        {
            temp = hex[i] - 'a' + 10;
        }
        else if (IS_DIGIT(hex[i]))
        {
            temp = hex[i] - '0';
        }
        dec = dec * 16 + temp;

        i++;
    }
    return dec;
}


/*******************************************************************/
/******************    SELECT FUNCTIONS UTILS    *******************/
/*******************************************************************/

int     writeThroughSelect(int fd)
{
    int     rc;
    fd_set  writefds;
    FD_ZERO(&writefds);
    FD_SET(fd, &writefds);
    rc = select(fd + 1, 0, &writefds, NULL, NULL);
    if (rc < 0)
    {
        std::cerr << "  select() failed" << std::endl;
        FD_CLR(fd, &writefds);
        close(fd);
        return -1;
    }
    FD_CLR(fd, &writefds);
    return 0;
}

int     readThroughSelect(int fd)
{
    int     rc;
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    rc = select(fd + 1, &readfds, 0, NULL, NULL);
    if (rc < 0)
    {
        std::cerr << "  select() failed" << std::endl;
        FD_CLR(fd, &readfds);
        close(fd);
        return -1;
    }
    FD_CLR(fd, &readfds);
    return 0;
}

}; // end namespace utils