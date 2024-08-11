#ifndef SERVER_IOMANAGER_H
#define SERVER_IOMANAGER_H

#include <stdio.h>
#include <unistd.h>

// Function Prototypes
ssize_t readFromUser(int userFileDescriptor, void* const dataBuffer, size_t dataSize);
ssize_t writeToUser(int userFileDescriptor, void* const dataBuffer, size_t dataSize);

#endif // SERVER_IOMANAGER_H 
