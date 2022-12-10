#include <iostream>
#include "Node.h"
#include "Edge.h"

int main() 
{
	Node n1("A");
	Node n2("B");
	Node n3("C");
	Node n4("D");
	std::cout << "node: " << n1.getName() << ", " << n1.getValue() << std::endl;
	std::cout << "node: " << n2.getName() << ", " << n2.getValue() << std::endl;
	std::cout << "node: " << n3.getName() << ", " << n3.getValue() << std::endl;
	std::cout << "node: " << n4.getName() << ", " << n4.getValue() << std::endl;

	n1.addEdge(&n2, 2);
	n1.addEdge(&n3, 3);
	n2.addEdge(&n4, 4);

}
