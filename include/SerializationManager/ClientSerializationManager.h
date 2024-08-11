#ifndef SERIALIZATIONMANAGER_H
#define SERIALIZATIONMANAGER_H

// Function Prototypes
const char* serializeUserMessage(const char* deserializedServerMessage);
const char* deserializeUserMessage(const char* serializedServerMessage);

const char* serializeServerMessage(const char* deserializeUserMessage);
const char* deserializeServerMessage(const char* serializedUserMessage);

#endif //SERIALIZATIONMANAGER_H
