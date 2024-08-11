#include "../../../include/IOManager/ServerIOManager.h"

char* readFromAdmin(char* const dataBuffer, size_t dataSize){ return fgets(dataBuffer, dataSize, stdin); }

ssize_t readFromUser(int userFileDescriptor, void* const dataBuffer, size_t dataSize){ return read(userFileDescriptor, dataBuffer, dataSize); }

ssize_t writeToUser(int userFileDescriptor, void* const dataBuffer, size_t dataSize){ return write(userFileDescriptor, dataBuffer, dataSize); }
