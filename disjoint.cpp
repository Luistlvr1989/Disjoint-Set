#include "disjoint.h"

void DisjointSet::makeSet(int data) {
    Node* node = new Node(data);
    this->nodes[data] = node;
}

bool DisjointSet::unionSet(int data1, int data2) {
    Node* parent1 = findSet(data1);
    Node* parent2 = findSet(data2);

    if (parent1 != parent2) {
        if (parent1->rank >= parent2->rank) {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        } else {
            parent1->parent = parent2;
        }

        return true;
    }

    return false;
}

Node* DisjointSet::findSet(int data) {
    return findSet(this->nodes[data]);
}

Node* DisjointSet::findSet(Node* node) {
    Node* current = node;
    while (current != current->parent) {
        current = current->parent;
    }

    node->parent = current;
    return current;
}