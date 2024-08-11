#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <unistd.h>
#include <sys/socket.h>

int removeUser(int userSocketFD);
int addUser(int serverSocketFD, struct sockaddr* serverSocketAddress, socklen_t serverSocketAddressLength);
int setupChatroom(const struct sockaddr* serverSocketAddress, socklen_t serverSocketAddressLength, int port);

#endif // NETWORKMANAGER_H
