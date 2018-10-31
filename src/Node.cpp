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
    children(kids), is_min(im), value(init_val) {}


Node::~Node() {
    for (Node* child: children) {
        delete child;
    }
}


int Node::eval() {
    // Base Case for leaf nodes
    if (children.size() == 0) {
        return this->value;
    }

    // Simple linear search
    int sel_val = children[0]->value;

    // Search for the min or max
    if (is_min) {   // Min node

        for (int i = 1; i < children.size(); ++i) {
            children[i]->eval();
            if (children[i]->value < sel_val) {
                sel_val = children[i]->value;
            }
        }

    }
    else {      // Max node

        for (int i = 1; i < children.size(); ++i) {
            children[i]->eval();
            if (children[i]->value < sel_val) {
                sel_val = children[i]->value;
            }
        }
        
    }

    this->value = sel_val;
    
    return this->value;
}