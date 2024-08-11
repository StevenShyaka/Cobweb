#include "../../../include/IOManager/ClientIOManager.h"

char* readFromUser(char* const dataBuffer, size_t dataSize){ return fgets(dataBuffer, dataSize, stdin); }

void writeToUser(const char* const dataBuffer){ printf("%s", dataBuffer); }

ssize_t readFromServer(int serverFileDescriptor, void* const dataBuffer, size_t dataSize){ return read(serverFileDescriptor, dataBuffer, dataSize); }

ssize_t writeToServer(int serverFileDescriptor, void* const dataBuffer, size_t dataSize){ return write(serverFileDescriptor, dataBuffer, dataSize); }
