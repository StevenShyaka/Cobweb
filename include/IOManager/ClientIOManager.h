#ifndef CLIENT_IOMANAGER_H
#define CLIENT_IOMANAGER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

// Function Prototypes
char* readFromUser(char *dataBuffer, size_t dataSize);
void writeToUser(const char* const dataBuffer);
ssize_t readFromServer(int serverFileDescriptor, void* const dataBuffer, size_t dataSize);
ssize_t writeToServer(int serverFileDescriptor, void* const dataBuffer, size_t dataSize);

#endif // CLIENT_IOMANAGER_H 
