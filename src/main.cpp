#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "MeshNetwork.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //create the mesh network
    MeshNetwork* meshnet = new MeshNetwork;
    //create a node
    Node* node = new Node("1", "2", "3", "4", "5");
    //add a node to the network
    meshnet->addNode(node);


    printf("node attributes: %s %s %s %s %s", node->getfirmwareVersion(), node->getlocation(), node->getsensorType(), node->getserial(), node->getUniqueIdentifier());
    //factory pattern?


    return 0;
}

