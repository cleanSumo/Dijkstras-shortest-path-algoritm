#include <iostream>
#include "Node.h"

std::string Node::getName() const { return node_name; }

void 
Node::setValue(int v) { value = v; }

int 
Node::getValue() const { return value; }

void 
Node::addEdge(Node* destination, int length) 
{ 
	edges.emplace_back(destination, length); 
}

const std::vector<Edge>& 
Node::getEdges() const { return edges; }

bool 
operator<(const Node &n1, const Node &n2)
{ 
	return (n1.value < n2.value); 
}

std::ostream& 
operator<<(std::ostream& os, const Node& n)
{
	os << "Node [" << n.getName() << ", " << n.getValue() << "]";
	return os;
}

bool 
operator==(const std::shared_ptr<Node>& sp, const Node* n)
{
	std::cout << sp.get() << " =?= " << n << "\n";
	return sp.get() == n;
}
