#ifndef NODE_H
#define NODE_H

#include <vector>
#include <limits>
#include <memory>
#include "Edge.h"


class Node {
public:
	static constexpr int max_value{std::numeric_limits<int>::max()};

	/** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
	Node(const std::string& name)
		: node_name{name}, value{max_value} {};

	/** Hämtar nodens namn. */
	std::string getName() const;

	/** Sätter nodens värde till v. */
	void setValue(int v);

	/** Hämtar nodens värde. */
	int getValue() const;

	/** Lägger till en ny båge från denna nod till en given destination.
	Bågen ska ha längden length. */
	void addEdge(Node* destination, int length);

	/** Hämtar de bågar som utgår från denna nod. */
	const std::vector<Edge>& getEdges() const;

	friend bool operator<(const Node&, const Node&);
	friend std::ostream& operator<<(std::ostream&, const Node&);

//hmmmmmm
	friend bool operator==(std::unique_ptr<Node>, const Node*);

private:
	std::vector<Edge> edges;
	std::string node_name;
	int value;
};


#endif