#include "Edge.h"

Edge::Edge(int start, int end, int weight)
{
	
	this->end = end;
	this->start = start;
	this->weight = weight;
}

Edge::Edge()
{
	
	this->end = 0;
	this->start = 0;
	this->weight = 0;
}
