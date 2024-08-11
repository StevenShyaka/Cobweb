#include "../../../include/SerializationManager/ClientSerializationManager.h"

const char* serializeUserMessage(const char* deserializedServerMessage);
const char* deserializeUserMessage(const char* serializedServerMessage);

const char* serializeServerMessage(const char* deserializeUserMessage);
const char* deserializeServerMessage(const char* serializedUserMessage);
