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

Node::Node(vector<Node*> kids, bool im, int init_val): 
    move(init_val), is_min(im), children(kids), value(0) {}

Node::~Node() {
    // Implement...?
    // for loop
    //delete &children[i];
}

int Node::eval() {
    // Base Case for recursion:
    if (children.size() == 0) {
        // determine "sortedness" after move
        return value;
    }

    // Evaluate the children
    for (Node* child:children) {
        child->eval();
    }

    // Then search for the min or max
    if (is_min) {   // Min node

        // Simple linear search
        Node* min_node = children[0];

        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->data < min_node->data) {
                min_node = children[i];
            }
        }

        return min_node->data;
    }
    else {      // Max node

        // Simple linear search
        Node* max_node = children[0];

        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->data > max_node->data) {
                max_node = children[i];
            }
        }

        return max_node->data;
    }
}