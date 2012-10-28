#include "Starbucks.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

#ifndef _NODE_H_
#define _NODE_H_

class Node {
public:
	Node* left_;	
	Node* right_;
	Entry* data_;
	Node();
	Node(Node* r);
	Node(Entry c);
};
#endif

class womackscStarbucks : public Starbucks {
  public:
	Entry* location_;
	int num_items_;
	Node* root;

	womackscStarbucks(string data);
	void readInFile(string data);
	Node* insert (Entry e, Node* r, bool xLevel);
	void build(Entry* c, int n);
	Entry* search (double x, double y, Node* r, bool xLevel);
	Entry* getNearest(double x, double y);
	string printLocationChange(double x, double y);
	
};