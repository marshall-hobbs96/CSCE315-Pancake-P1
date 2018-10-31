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
#include <iostream>

using namespace std;

Node::Node(vector<Node*> kids, bool im, int init_val, vector<int> curr_path): 
    children(kids), is_min(im), value(init_val), path(curr_path) {}


Node::~Node() {
    for (Node* child: children) {
        delete child;
    }
}

vector<Node*> Node::getChildren() {
    return children;
}

int Node::getValue() {
    return value;
}


int Node::eval() {
    // Base Case for leaf nodes
    if (children.size() == 0) {
        return this->value;
    }

    // Simple linear search
    int sel_val = children[0]->eval();

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
            if (children[i]->value > sel_val) {
                sel_val = children[i]->value;
            }
        }

    }

    this->value = sel_val;
    
    return this->value;
}