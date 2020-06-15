#pragma once
#include "Node.h"


class MeshNetwork {
public:
	MeshNetwork();
	~MeshNetwork();
	int addNode(Node* node);
	void removeNode(Node* node);
	void createNetwork();
	void visualizeNetwork(int numberOfNodes);
private:
	Node* nodearr;
};