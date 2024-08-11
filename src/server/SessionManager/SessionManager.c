#include <poll.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "../../../include/NetworkManager/ServerNetworkManager.h"

int main()
{
    int port = 8080;
    struct sockaddr_in serverSocketAddress;
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(port);
    serverSocketAddress.sin_addr.s_addr = INADDR_ANY;

    int serverSocketFD =  setupChatroom((struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress), port);
    if (serverSocketFD < 0)
        return -1;

    if (listen(serverSocketFD, 3) < 0)
        return -1;

    struct pollfd *socketFD = (struct pollfd*)malloc(sizeof(struct pollfd[12]));

    // File Descriptor for stdin
    socketFD[0].fd = 0;
    socketFD[0].events = POLLIN;

    // File Descriptor for connection monitoring
    socketFD[1].fd = serverSocketFD;
    socketFD[1].events = POLLIN;

    while(1)
    {
        
    }

    free(socketFD);
    return 0;
}
