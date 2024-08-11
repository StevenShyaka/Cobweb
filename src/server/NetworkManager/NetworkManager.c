#include "../../../include/NetworkManager/ServerNetworkManager.h"
#include <sys/socket.h>

int setupChatroom(const struct sockaddr* serverSocketAddress, socklen_t serverSocketAddressLength, int port)
{
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0)
        return -1;

    // This means that we're setting the flags to a value of 1
    // Meaning reuseaddr and reuseport flags are now set to 1
    int optionValue = 1;
    if (setsockopt(socketFD, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optionValue, sizeof(optionValue)))
        return -1;

    if (bind(socketFD, serverSocketAddress, serverSocketAddressLength) < 0)
        return -1;

    return socketFD;
}

int addUser(int serverSocketFD, struct sockaddr* serverSocketAddress, socklen_t serverSocketAddressLength){ return accept(serverSocketFD, serverSocketAddress, &serverSocketAddressLength); }

int removeUser(int userSocketFD){ return close(userSocketFD); }
