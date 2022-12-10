#ifndef EDGE_H
#define EDGE_H

#include <iostream>
class Node;

class Edge {
public:
	/** Skapa en ny båge till noden destination, med längden length. */
	Edge(Node* destination, int distance);
	~Edge() =default;

	/** Hämtar bågens destination. */
	Node* getDestination() const;

	/** Hämtar bågens längd. */
	int getLength() const;

	friend std::ostream& operator<<(std::ostream& os, const Edge& e);

private:
	Node* dest;
	int length;
};

#endif