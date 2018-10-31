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

    // Simple linear search
    vector<Node*> path = children[0]->eval();
    int sel_val = children[0]->value;

    // Search for the min or max
    if (is_min) {   // Min node

        for (int i = 1; i < children.size(); ++i) {
            vector<Node*> temp_path = children[i]->eval();
            if (children[i]->value < sel_val) {
                sel_val = children[i]->value;
                path = temp_path;
                path.push_back(children[i]);
            }
        }

    }
    else {      // Max node

        for (int i = 1; i < children.size(); ++i) {
            vector<Node*> temp_path = children[i]->eval();
            if (children[i]->value > sel_val) {
                sel_val = children[i]->value;
                path = temp_path;
            }
        }
    }

    this->value = sel_val;
    path.push_back(this);
    
    return path;
}