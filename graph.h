#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

class Graph {
public:
	Graph();
	/* Skapar en graf med noder och bågar som läses från strömmen in. */
	Graph(std::istream&);


	Node* find(const std::string&);
	void addNode(const std::string&);
	void resetVals();

	std::vector<std::unique_ptr<Node>>::iterator begin() 
		{ return nodes.begin(); }
	std::vector<std::unique_ptr<Node>>::iterator end() 
		{ return nodes.end(); }	


private:
	void insert(std::string&, std::string&, int&);
	std::vector<std::unique_ptr<Node>> nodes;
};


#endif