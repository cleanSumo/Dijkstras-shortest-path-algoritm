#include <iostream>
#include <memory>
#include <vector>

#include "Node.h"
#include "Edge.h"

#include "Graph.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

Graph::Graph() {}

/** Skapar en graf med noder och bågar som läses från strömmen in. */
Graph::Graph(std::istream& in) 
{
	std::string name, neighbor;
	int dist;
	while( in.good() )
	{	
		std::getline(in, name, ':');
		in >> dist;
		std::getline(in, neighbor, ' ');
		std::getline(in, neighbor);
		insert(name, neighbor, dist);
	}
}


Node* Graph::find(const std::string& s)
{
	for ( auto&& node : nodes)
	{
		if( node.get()->getName() == s) return node.get();
	}
	return nullptr;
}

void Graph::addNode(const std::string& s)
{
	nodes.emplace_back(std::unique_ptr<Node>(new Node(s)));
}

void Graph::resetVals()
{
	for (auto&& node_ptr : nodes)
	{
		node_ptr.get()->setValue(Node::max_value);
	}
}

void Graph::insert(string& name, string& neighbor, int& dist)
{
	if( find(name) == nullptr ) addNode(name);
	Node* n = find(name);
	Node a(neighbor);
	n->addEdge(&a, dist);
}

// vector<unique_ptr<Node>>::iterator begin() 
// vector<unique_ptr<Node>>::iterator end() 
// vector<unique_ptr<Node>> nodes;