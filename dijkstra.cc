
#include <iostream>
#include "dijkstra.h"
#include "Graph.h"
#include "NodeSet.h"

using std::cout;
using std::endl;


void dijkstra(Node* n)
{
	n->setValue(0);
	NodeSet stack;
	stack.add(n);

	// print_neighbors(n);

	while( !stack.isEmpty() )
	{	
		auto node = stack.removeMin();
		process_neighbors(node, stack);
	}

}

void process_neighbors(Node* node, NodeSet& stack)
{
	for (auto neighbor : node->getEdges())
	{
		Node* dest = neighbor.getDestination();

		int length = neighbor.getLength();
		int value = node->getValue();
		int sum = length + value;

		if( sum < dest->getValue() ) 
		{
			dest->setValue(sum);
			stack.add(dest);
		}
	}
}


void print_neighbors(Node* n) 
{
	std::cout << "neighbors to: " << *n << " is\n";
	for(auto de : n->getEdges()){
		cout << "  -" << de << endl; 
    }
}