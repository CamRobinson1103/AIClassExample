#include "Node.h"
#include <raylib.h>
#include "Edge.h"

Node::Node(int x, int y, int nodeSize)
{
	graphPosition.x = x;
	graphPosition.y = y;
	size = nodeSize;
}

void Node::draw()
{
	//Draws a circle for the node
	DrawCircle(getWorldPosition().x * 32, getWorldPosition().y * 32, size, GetColor(color));
	//Draws edged
	for (int i = 0; i < edges.size(); i++)
	{
		//Checks if the node is the first connected node to prevent the edge from drawing twice
		if (edges[i]->connectNode1->graphPosition == graphPosition)
		{
			edges[i]->draw();
		}
	}

}

void Node::update(float deltaTime)
{
	Actor::update(deltaTime);
	for (int i = 0; i < edges.size(); i++)
	{
		//Checks if the node is the first connected node to prevent the edge from drawing twice
		if (edges[i]->connectNode1->graphPosition == graphPosition)
		{
			edges[i]->update(deltaTime);
		}
	}
}
		
