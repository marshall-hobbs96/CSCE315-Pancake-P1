/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

MMTree.h - Interface for the Minimax Tree Implementation
*/

#ifndef __MMTREE__        // For #including more than once
#define __MMTREE__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>
#include <map>
#include "Node.h"


/************************************************
 * Main Class
 ***********************************************/

template <typename T>
class MMTree {
private:
    Node* root;
    int depth;
    Node* make_tree(T func, int d, int num_children, bool is_minimum, vector<int> path_so_far);

public:
    MMTree<T>(T func, int d, int num_children);
    ~MMTree<T>();
    int eval();

    int bestMove();
};

template <typename T>
Node* MMTree<T>::make_tree(T func, int d, int num_children, bool is_minimum, vector<int> path_so_far) {

    // Base case: leaf nodes
    if (d == 1) {

        vector<Node*> no_kids;      // for the leaf nodes
        vector<Node*> child_nodes;  // for the children of the depth=1 node

        for (int i = 0; i < num_children; i++) {
            vector<int> temp = path_so_far;
            temp.push_back(i);
            int utility_val = func(temp);
            // Initialize to utility value (is_min does not matter)
            child_nodes.push_back(new Node(no_kids, false, utility_val, temp));
        }

        // Make the root be a min node
        return new Node(child_nodes, is_minimum, 0, path_so_far);
    }

    // Recursively:
    vector<Node*> children;
    for (int i = 0; i < num_children; i++) {
        vector<int> temp_path = path_so_far;
        temp_path.push_back(i);
        children.push_back(make_tree(func, d-1, num_children, !is_minimum, temp_path));
    }

    // Initialize root to 0 (doesn't matter):
    return new Node(children, is_minimum, 0, path_so_far);
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
    for (int i = 0; i < root->getChildren().size(); i++) {
        if (root->getChildren()[i]->getValue() == best_score) {
            return i;
        }
    }

    // Return for an invalid input:
    return -1;
}

#endif