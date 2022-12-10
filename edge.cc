#include "Edge.h"
#include "Node.h"

Edge::Edge(Node* destination, int distance)
{
	dest = destination;
	length = distance;
}
/** Hämtar bågens destination. */
Node* Edge::getDestination() const
{ 
	return dest; 
}

/** Hämtar bågens längd. */
int Edge::getLength() const 
{ 
	return length; 
}

std::ostream& 
operator<<(std::ostream& os, const Edge& n)
{
	os << "Edge [" << n.getDestination()->getName() << ", " << n.getLength() << "]";
	return os;
}

