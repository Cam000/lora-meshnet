//my includes
#include "Node.h"

//LoRa RX and TX buffer size
constexpr auto LoRablockSize = 8;
constexpr auto LoRablockCount = 128;

//WiFi RX and TX buffer size
constexpr auto WiFiblockSize = 8;
constexpr auto WiFiblockCount = 128;

//##Node definitions
Node::Node() {
	//set me up
	//initialize LoRa buffers on the heap
	LoRarxbuffer = (char*)calloc(LoRablockCount, LoRablockSize);
	LoRatxbuffer = (char*)calloc(LoRablockCount, LoRablockSize);
	//set init state
	setState(state::INIT);
}

Node::Node(const char* firmwareVersion, const char* misc, const char* sensorType, const char* serial, const char* uniqueIdentifier) {
	//set me up
	//initialize LoRa buffers on the heap
	LoRarxbuffer = (char*)calloc(LoRablockCount, LoRablockSize);
	LoRatxbuffer = (char*)calloc(LoRablockCount, LoRablockSize);
	//set init state
	setState(state::INIT);
	//initialize node attributes on the heap
	nodeAttributes = new nodeattr;
	strcpy_s(nodeAttributes->firmwareVersion, 25, firmwareVersion);
	strcpy_s(nodeAttributes->location, 50, misc);
	strcpy_s(nodeAttributes->uniqueIdentifier, 25, uniqueIdentifier);
	strcpy_s(nodeAttributes->serial, 25, serial);
	strcpy_s(nodeAttributes->sensorType, 25, sensorType);
}
Node::~Node() {
	free(LoRarxbuffer);
	free(LoRatxbuffer);
	
	delete nodeAttributes;
}

int Node::sendMessage() {

	return 0;
}

int Node::rcvMessage() {

	return 0;
}

void Node::setState(Node::state mstate) {
	mState = mstate;
}

Node::state Node::getState() {
	return mState;
}

char* Node::getUniqueIdentifier()
{
	return nodeAttributes->uniqueIdentifier;
}

char* Node::getfirmwareVersion()
{
	return nodeAttributes->firmwareVersion;
}

char* Node::getsensorType()
{
	return nodeAttributes->sensorType;
}

char* Node::getserial()
{
	return nodeAttributes->serial;
}

char* Node::getlocation()
{
	return nodeAttributes->location;
}



//##SensorNode definitions

SensorNode::SensorNode() {
	sensorVal = -1;
	sensorThreshold = -1;

}

int SensorNode::relayMessage() {

	return 0;
}


//##GatewayNode definitions

GatewayNode::GatewayNode() {
	WiFirxbuffer = (char*)calloc(WiFiblockCount, WiFiblockSize);
	WiFitxbuffer = (char*)calloc(WiFiblockCount, WiFiblockSize);
}

GatewayNode::~GatewayNode() {
	free(WiFirxbuffer);
	free(WiFitxbuffer);
}

int GatewayNode::bridgeToEthernet() {


	return 0;
}

int GatewayNode::bridgeToWiFi() {


	return 0;
}