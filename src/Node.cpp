/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

Node.cpp - Node implementation for holding tree data
*/

#include "Node.h"

using namespace std;

Node::Node(vector<Node*> kids, bool im, int init_val): 
    value(init_val), is_min(im), children(kids) {}

/*
Node::~Node() {
    for (Node* child: children) {
        delete child;
    }
}
*/

int Node::eval() {
    // Base Case for recursion:
    if (children.size() == 0) {
        return value;
    }

    // Search for the min or max
    if (is_min) {   // Min node
        // Simple linear search
        Node* min_node = children[0];
        int min_value = children[0]->eval();     // has to be at least one child

        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->eval() < min_value) {
                min_node = children[i];
            }
        }

        return min_node->value;
    }
    else {      // Max node
        // Simple linear search
        Node* max_node = children[0];
        int max_value = children[0]->eval();     // has to be at least one child

        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->eval() > max_value) {
                max_node = children[i];
            }
        }

        return max_node->value;
    }
}