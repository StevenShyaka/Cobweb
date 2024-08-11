#include "../../../include/NetworkManager/ClientNetworkManager.h"
int joinChatRoom(const char* serverAddress, int port)
{
    struct sockaddr_in serverSocketAddress;
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0)
        return -1;

    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(port);
    // Convert IPv4 address from string to binary
    if (inet_pton(AF_INET, serverAddress, &serverSocketAddress.sin_addr) <= 0)
        return -1;

    if (connect(socketFD, (struct sockaddr*)&serverSocketAddress, sizeof(serverSocketAddress)) < 0)
        return -1;
    return socketFD;
}

int leaveChatRoom(int serverSocketFD){ return close(serverSocketFD); }
