#include <poll.h>
#include <string.h>
#include "../../../include/IOManager/ClientIOManager.h"
#include "../../../include/NetworkManager/ClientNetworkManager.h"

int main()
{
    int numFD = 2;
    int port = 8080;
    int buffSize = 512;
    int timeout = 5000;
    char userInput[buffSize];
    struct pollfd ioFD[numFD];
    char serverAddress[] = "127.0.0.1";
    char exitCMD[] = "/exit\n";

    // File Descriptor for stdin
    ioFD[0].fd = 0;
    ioFD[0].events = POLLIN;

    int serverSocketFD = joinChatRoom(serverAddress, port);
    if (serverSocketFD == -1)
        return -1;

    // File Descriptor for server
    ioFD[1].fd = serverSocketFD;
    ioFD[1].events = POLLIN;

    while (1)
    {
        int result = poll(ioFD, numFD, timeout);
        if (result == -1)
            return -1;
        else if (result > 0)
        {
            if (ioFD[0].revents & POLLIN)
            {
                readFromUser(userInput, buffSize);
                if (strcmp(userInput, exitCMD) == 0)
                    break;
                writeToServer(serverSocketFD, userInput, buffSize);
            }
            else if (ioFD[1].revents & POLLIN)
            {
                readFromServer(serverSocketFD, userInput, buffSize);
                if (strcmp(userInput, exitCMD) == 0)
                    break;
                writeToUser(userInput);
            }
        }
    }

    return leaveChatRoom(serverSocketFD);
}
