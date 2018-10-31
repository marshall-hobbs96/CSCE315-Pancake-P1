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

/*
int MMTree::getSortedness(int* stack_order, const int stack_size) {
    // Array of ls and gs for less than and greater than
    char* comparators = new char[stack_size];
    comparators[0] = 'l';

    for (int i = 0; i < stack_size - 1; i++) {
        if (stack_order[i] < stack_order[i+1]) 
            comparators[i+1] = 'l';
        else
            comparators[i+1] = 'g';
    }

    // Count the changes in sign from left to right
    int count = 0;
    for (int i = 0; i < stack_size - 1; i++)
        if (comparators[i] != comparators[i+1])
            count++;

    delete[] comparators;
    
    return count;
}
*/

/*
int MMTree::utility(int* temp_stack, int temp_stack_size, int* flip_sequence, int sequence_size) {
    // Get the sortedness advatage before flipping
    //int init_sortedness = getSortedness(temp_stack, temp_stack_size);

    // do all the flips
    //for (int i=0; i < sequence_size; i++) {

    //}

    // get the sortedness advatage after flipping
    // calculate the difference after - before
    // do all the flips in reverse order to put it back
    // return the difference
}
*/

template <typename T>
Node* MMTree<T>::make_tree(T func, int d, int num_children, bool is_minimum) {

    // Base case: leaf nodes
    if (depth == 1) {

        vector<Node*> no_kids;      // for the leaf nodes
        vector<Node*> child_nodes;  // for the children of the depth=1 node

        for (int i = 0; i < num_children; i++) {
            int utility_val = func(i);
            // Initialize to utility value (is_min does not matter)
            Node* leaf = new Node(no_kids, false, utility_val);
            child_nodes.push_back(leaf);
        }

        // Make the root be a min node
        Node* root = new Node(child_nodes, is_minimum, 0);
        return root;
    }

    // Recursively:
    vector<Node*> children;
    for (int i = 0; i < num_children; i++) {
        Node* temp = make_tree(func, d-1, num_children, !is_minimum);
        children.push_back(temp);
    }

    // Initialize root to 0 (doesn't matter):
    Node* root = new Node(children, is_minimum, 0);

    return root;
}

template <typename T>
MMTree<T>::MMTree(T func, int d, int num_children) : depth(d) {
    // The root node should always be a min tree:
    root = make_tree(func, d, num_children, true);
}

template <typename T>
MMTree<T>::~MMTree() {
    delete root;
}

template <typename T>
int MMTree<T>::eval() {
    return root->eval();
}

template <typename T>
int MMTree<T>::bestMove() {
    return 0;
}