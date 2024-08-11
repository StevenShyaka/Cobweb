#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int joinChatRoom(const char* serverAddress, int port);
int leaveChatRoom(int serverSocketFD);

#endif // NETWORKMANAGER_H
