# include <csignal>
# include "server.hpp"

# define DEFAULT_CONF "conf/webserv.conf"

void 	signal_handler(int signo)
{
	if (signo == SIGINT)
    {
        std::cout << "\n\033[0;31mInterrupt signal caught.\nWe will stop the server\033[0m\n" << std::endl;
        isRunning = false;
    }
}

int     checkSelect(int maxSd, fd_set *readfds, fd_set *writefds)
{
    struct timeval      timeout;
    timeout.tv_sec  = 3 * 60;
    timeout.tv_usec = 0;

    int     rc;
    rc = select(maxSd + 1, readfds, writefds, NULL, &timeout);
    if (rc < 0)
    {
       std::cerr << "Select() failed. " << std::endl;
       std::cerr << strerror(errno) << std::endl << std::endl;
       return -1;
    }
    if (rc == 0)
    {
       std::cerr << "Select() timed out. End program." << std::endl;
       return -1;
    }
    return 0;
}

int     main(int ac, char **av)
{
    HTTPServer          server;
    std::string         confFile;
    std::vector<int>    listenSDs;
    fd_set              readfds;
    fd_set              writefds;

    if (ac > 2)
    {
        std::cout << "Error: too many arguments." << std::endl;
        return 1;
    }
    if (ac == 2)
        confFile = av[1];
    else
        confFile = DEFAULT_CONF;
    
    /* Server initialisation */
    server.loadConfig(confFile);
    server.initServers();
    server.initFdSets();
    listenSDs = server.getSockets();
    
    std::cout << "\n\033[0;33mWebserver is running and ready to accept requests...\033[0m\n" << std::endl;

    /* Main server loop */
    signal(SIGINT, signal_handler);
    while (isRunning)
    {
        readfds = server.readMaster;
        writefds = server.writeMaster;

        // std::cout << "\n\033[0;33mWaiting for event on select...\033[0m\n";
        int maxSd = *std::max_element(server.sdList.begin(), server.sdList.end());
        if (checkSelect(maxSd, &readfds, &writefds) < 0)
            break ;

        for (std::list<int>::iterator sd = server.sdList.begin(); sd != server.sdList.end(); sd++)
        {
            Client *c = server.matchClient(*sd);
            if (c != NULL && c->checkTimeout(utils::getTime()) == 1)
            {
                server.cleanConnection(c);
                break;
            }
            if (FD_ISSET(*sd, &readfds))
            {
                if (isRunning && std::find(listenSDs.begin(), listenSDs.end(), *sd) != listenSDs.end())
                {
                    server.acceptNewConnection(*sd);
                }
                else
                {
                    // std::cout << "\033[1;37mReady for read - socket : " << *sd << "\033[0m" << std::endl;
                    if (c->receiveReq(*sd) == -1)
                    {
                        server.cleanConnection(c);
                        break;
                    }
                    if (c->isDoneRecv())
                    {
                        FD_SET(*sd, &server.writeMaster);
                    }
                }
            }
            if (FD_ISSET(*sd, &writefds))
            {
                if (c->getBufOut().empty())
                {
                    server.handleRequest(c);
                    /* FOR DEBUG */
                    // c->getRequest()->printRequest();
                    // std::cout << "State: " << c->getState() << std::endl;
                    /* ----- */
                    if (c->getState() < Complete)
                    {
                        FD_CLR(*sd, &server.writeMaster);
                        break;
                    }
                    // std::cout << "\033[1;37mReady for write - socket : " << *sd << "\033[0m" << std::endl;
                    server.handleResponse(c);
                }
                if (c->sendResponse() == -1 || c->getState() == Unavailable)
                {
                    server.cleanConnection(c);
                    break;
                }
                if (c->getBufOut().empty())
                {
                    FD_CLR(c->getSocket(), &server.writeMaster);
                }
            }
        } // end for loop
    } // end while(isRunning)
    return 0;
}