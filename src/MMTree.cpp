/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

MMTree.cpp - Implementation for Minimax tree to evaluate the tree
*/

#include "MMTree.h"

MMTree::MMTree(int* stack, int d) : depth(d) {
    // Implementation...
}

MMTree::~MMTree() {
    delete root;
}

int MMTree::eval() {
    return root->eval();
}