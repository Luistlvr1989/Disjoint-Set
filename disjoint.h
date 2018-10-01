#ifndef DISJOINT_H
#define DISJOINT_H

#include <iostream>
#include <map>

#include "node.h"

using namespace std;

class DisjointSet {
    private:
        map<int, Node*> nodes;

    public:

        DisjointSet() {};
        void makeSet(int data);
        bool unionSet(int data1, int data2);
        Node* findSet(int data);
        Node* findSet(Node* node);
        ~DisjointSet() {};
};

#endif