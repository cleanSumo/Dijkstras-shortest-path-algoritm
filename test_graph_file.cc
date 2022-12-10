#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <fstream>
#include <set>

#include "graph.h"

using std::cout;
using std::endl;

void print_neighbours(Node* n)
{
    cout << "Anslutningar från " << n->getName() << "(" << n->getValue() << ") :\n";
    for(auto de : n->getEdges()){
        cout << de.getLength() << " to " << de.getDestination()->getName() << endl;
    }
}

Node* find_and_test(const std::string& s, Graph& g)
{
    Node* n = g.find(s);
    assert(n != nullptr);
    assert(n->getName() == s);
    assert(n->getValue() == Node::max_value);
    return n;
}

void test_graph(Graph& g)
{
    auto n_lund = find_and_test("Lund", g);
	// if (n_lund != nullptr ) print_neighbours(n_lund);
    find_and_test("Dalby", g);
    find_and_test("Sodra Sandby", g);
    find_and_test("Veberod", g);
    find_and_test("Torna Hallestad", g);
    find_and_test("Staffanstorp", g);
    find_and_test("Lomma", g);
    find_and_test("Bjarred", g);
    auto n_Kavlinge = find_and_test("Kavlinge", g);

    n_lund->setValue(17);
    auto n2 = g.find("Lund");
    assert(n2->getValue()==17);

    auto n3 = g.find("Kavlinge");
    n_Kavlinge->setValue(42);
    assert(n3->getValue()==42);

    g.resetVals();
    for(auto it = g.begin(); it != g.end(); ++it){
        assert((*it)->getValue() == Node::max_value);
    }

    cout << "test_graph with file input passed" << endl;
}


int main()
{
	std::ifstream in_file("test_graph.txt");
 
    Graph g(in_file);

    test_graph(g);
    return 0;
}
