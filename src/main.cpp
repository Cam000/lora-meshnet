#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "MeshNetwork.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //create the mesh network
    MeshNetwork* meshnet = new MeshNetwork;
    //create a node
    GatewayNode* node = new GatewayNode("1", "2", "3", "4", "5");
    SensorNode* node1 = new SensorNode("11", "22", "33", "44", "55");
    SensorNode* node2 = new SensorNode("111", "222", "333", "444", "555");
    //add a node to the network
    int numberOfNodes;
    numberOfNodes = meshnet->addNode(node);
    numberOfNodes = meshnet->addNode(node1);
    numberOfNodes = meshnet->addNode(node2);

    meshnet->visualizeNetwork(numberOfNodes);


    return 0;
}

