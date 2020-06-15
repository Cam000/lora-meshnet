#pragma once
#include "Node.h"

class MeshNetwork {
public:
	MeshNetwork();
	~MeshNetwork();
	void addNode(Node* node);
	void removeNode(Node* node);
	void createNetwork();
	void visualizeNetwork();
};