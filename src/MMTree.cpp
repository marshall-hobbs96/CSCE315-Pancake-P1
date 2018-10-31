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

template <typename T>
Node* MMTree<T>::make_tree(T func, int d, int num_children, bool is_minimum, vector<int> path_so_far) {

    // Base case: leaf nodes
    if (depth == 1) {

        vector<Node*> no_kids;      // for the leaf nodes
        vector<Node*> child_nodes;  // for the children of the depth=1 node

        for (int i = 0; i < num_children; i++) {
            vector<int> temp = path_so_far;
            temp.push_back(i);
            int utility_val = func(temp);
            // Initialize to utility value (is_min does not matter)
            Node* leaf = new Node(no_kids, false, utility_val, temp);
            child_nodes.push_back(leaf);
        }

        // Make the root be a min node
        Node* root = new Node(child_nodes, is_minimum, 0, path_so_far);
        return root;
    }

    // Recursively:
    vector<Node*> children;
    for (int i = 0; i < num_children; i++) {
        vector<int> temp = path_so_far;
        temp.push_back(i);
        Node* temp = make_tree(func, d-1, num_children, !is_minimum, temp);
        children.push_back(temp);
    }

    // Initialize root to 0 (doesn't matter):
    Node* root = new Node(children, is_minimum, 0, path_so_far);
    return root;
}

template <typename T>
MMTree<T>::MMTree(T func, int d, int num_children) : depth(d) {
    // The root node should always be a min tree:
    vector<int> path_to_track;
    root = make_tree(func, d, num_children, true, path_to_track);
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
    // Evaluate the tree to find the best move
    int best_score = root->eval();

    // See which node matches that number
    for (int i = 0; i < root->children.size(); i++) {
        if (root->children[i]->value == best_score) {
            return i;
        }
    }

    // Return for an invalid input:
    return -1;
}