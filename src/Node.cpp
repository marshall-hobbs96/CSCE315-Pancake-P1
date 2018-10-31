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


vector<Node*> Node::eval() {
    // Base Case for leaf nodes
    if (children.size() == 0) {
        vector<Node*> v;
        v.push_back(this);
        return v;
    }

    // Search for the min or max
    if (is_min) {   // Min node
        // Simple linear search
        vector<Node*> min_path = children[0]->eval();
        int min_val = children[0]->value;

        for (int i = 1; i < children.size(); ++i) {
            vector<Node*> temp_path = children[i]->eval();
            if (children[i]->value < min_val) {
                min_val = children[i]->value;
                min_path = temp_path;
            }
        }

        this->value = min_node->value;
        return this->value;
    }
    else {      // Max node
        // Simple linear search
        Node* max_node = children[0];

        for (int i = 0; i < children.size(); ++i) {
            if (children[i]->eval() < max_node->value) {
                max_node = children[i];
            }
        }

        this->value = max_node->value;
        return this->value;
    }
}