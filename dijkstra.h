#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Node.h"
#include "NodeSet.h"
#include "Edge.h"
#include <vector>

/** Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
där värdet anger det kortaste avståndet från noden start.
Alla noder förutsätts, när funktionen anropas, ha ett värde som är
större än alla faktiska avstånd i grafen.
*/
void dijkstra(Node*);
void print_neighbors(Node*);
void process_neighbors(Node*, NodeSet&);

#endif

