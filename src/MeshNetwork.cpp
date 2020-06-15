#include "MeshNetwork.h"

#define MAX_RANGE 100

MeshNetwork::MeshNetwork()
{
	//initialize mesh network
	nodearr = new Node[128];
}

MeshNetwork::~MeshNetwork()
{
}

void MeshNetwork::createNetwork()
{
}

int MeshNetwork::addNode(Node* node)
{
	//add node ptr to array of nodes
	static int i = 0;
	nodearr[i] = *node;
	i++;
	return i;
}

void MeshNetwork::removeNode(Node* node)
{
}


void MeshNetwork::visualizeNetwork(int numberOfNodes)
{
	//tests
	for (int i = 0; i < numberOfNodes; i++) {

		Node nodeptr = nodearr[i];
		printf("node (%d) attributes: %s %s %s %s %s",i+1, nodeptr.getfirmwareVersion(), nodeptr.getlocation(), nodeptr.getsensorType(), nodeptr.getserial(), nodeptr.getUniqueIdentifier());
		printf("\r\n");



	}


	//generate GUI based on nodes and simulate routing

	//put Gateway in the middle
	//put sensor nodes random distance from center (rand x an y offset)
}
