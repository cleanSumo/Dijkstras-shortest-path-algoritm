
#include "NodeSet.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>

/** Skapar en tom mängd av noder. */
NodeSet::NodeSet()
{
}
/** Lägger till noden node till mängden,
om mängden inte redan innehåller en nod med samma namn. */
/*void NodeSet::add(Node* node)
{
	std::cout << "puts in adr: " << node << "\n"; 
	if ( std::count(nodes.begin(), nodes.end(), node ) == 0 )
	{
		nodes.push_back( std::make_shared( *node ) );
		std::cout << "new adr: " << (nodes[nodes.size()-1].get()) << "\n"; 
	}

}*/
/** Returnerar true om mängden noder är tom. */
bool NodeSet::isEmpty() 
{
	// std::cout << "nodeset size: " << nodes.size() << "\n";
	return nodes.empty();
}
/** Väljer ut den nod som har lägst värde och returnerar den.
Den returnerade noden tas bort ur mängden.
Om mängden är tom returneras null. */
/*Node* NodeSet::removeMin()
{
	if ( isEmpty() ) return nullptr;

	std::cout << "adr before: " << nodes[0].get() << "\n";

	Node* temp = nodes[0].get();
	int index = 0;

	// std::cout << "'nodes' contains...\n";
	// std::cout << "  -" << *temp << std::endl; 

	for(size_t i=1; i<nodes.size(); ++i )
	{
		if ( nodes[i].get()->getValue() < temp->getValue() ) 
		{
			index = i;
		}
		// std::cout << "  -" << *nodes[i] << std::endl; 
	}
	temp = nodes[index].get();
	// std::cout << "removing:  " << *temp << std::endl; 

	nodes.erase(nodes.begin()+index);

	std::cout << "adr after:  " << temp << "\n";
	// for (auto n: nodes)
	// {
	// 	std::cout << *n << "\n";
	// }

	return temp;
}*/

// Node* NodeSet::operator[] (int i)
// {
// 	return nodes[i].get(); 
// }

void NodeSet::add(Node* node)
{
	// std::cout << "puts in adr: " << node << "\n"; 
	if ( std::count(nodes.begin(), nodes.end(), node ) == 0 )
	{
		nodes.push_back( node );
		// std::cout << "new adr: " << nodes[nodes.size()-1] << "\n"; 
	}

}

Node* NodeSet::removeMin()
{
	if ( isEmpty() ) return nullptr;

	Node* temp = nodes[0];
	int index = 0;

	// std::cout << "'nodes' contains...\n";
	// std::cout << "  -" << *temp << std::endl; 

	for(size_t i=1; i<nodes.size(); ++i )
	{
		if ( nodes[i]->getValue() < temp->getValue() ) 
		{
			index = i;
			temp = nodes[index];
		}
		// std::cout << "  -" << *nodes[i] << std::endl; 
	}
	// std::cout << "removing:  " << *temp << std::endl; 

	// delete nodes[index]; // behövs inte eftersom new aldig görs..

	nodes.erase(nodes.begin()+index);

	// std::cout << "adr after:  " << temp << "\n";

	// for (auto n: nodes)
	// {
	// 	std::cout << *n << "\n";
	// }

	return temp;
}

int NodeSet::size() 
{
	return nodes.size();
}