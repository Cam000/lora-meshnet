#pragma once
#include <iostream>

struct DiscoveryTable
{
    int nodesVisited[128];
    //?
};


class Node {

public:
    Node();
    Node(const char* firmwareVersion, const char* misc, const char* sensorType, const char* serial, const char* uniqueIdentifier);
    ~Node();
    int sendMessage();
    int rcvMessage();
    enum class state { INIT, ACTIVE, DEEPSLEEP };
    void setState(state);
    state getState();
    char* getUniqueIdentifier();
    char* getfirmwareVersion();
    char* getsensorType();
    char* getserial();
    char* getlocation();
    struct nodeattr {
        char uniqueIdentifier[25];
        char firmwareVersion[25];
        char sensorType[25];
        char serial[25];
        char location[50];
    };

private:
    state mState;
    nodeattr* nodeAttributes;
    char* LoRarxbuffer;
    char* LoRatxbuffer;
    
};

class SensorNode : public Node {
public:
    SensorNode(const char* firmwareVersion, const char* misc, const char* sensorType, const char* serial, const char* uniqueIdentifier);
    int relayMessage();

private:
    uint16_t sensorVal;
    uint16_t sensorThreshold;
};

class GatewayNode : public Node {
public:
    GatewayNode(const char* firmwareVersion, const char* misc, const char* sensorType, const char* serial, const char* uniqueIdentifier);
    ~GatewayNode();
    int bridgeToWiFi();
    int bridgeToEthernet();

private:
    char* WiFirxbuffer;
    char* WiFitxbuffer;
};
