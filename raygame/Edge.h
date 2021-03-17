#pragma once
#include "Actor.h"

class Node;

class Edge :
	public Actor
{
public:
	Edge(Node* node1, Node* node2);
	Node* connectNode1;
	Node* connectNode2;
	float cost;
	void draw() override;
	void update(float deltaTime) override;
};

