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
using namespace std;


/************************************************
 * Main Class
 ***********************************************/

template <typename T>
class MMTree {
private:
    Node* root;
    int depth;
    Node* make_tree(T func, int d, int num_children, bool is_minimum, vector<int> path_so_far);
    void printTree(Node* tree_root, int tabs);
public:
    MMTree<T>(T func, int d, int num_children);
    ~MMTree<T>();
    int eval();
    void print();
    int bestMove();
};

template <typename T>
Node* MMTree<T>::make_tree(T func, int d, int num_children, bool is_minimum, vector<int> path_so_far) {

    // For depth 0, return a terminal node with no children
    if (d == 0) {
        vector<Node*> no_kids;
        return new Node(no_kids, is_minimum, func(path_so_far), path_so_far);
    }

    // Recursively:
    vector<Node*> children;
    for (int i = 0; i < num_children; i++) {
        vector<int> temp_path = path_so_far;
        temp_path.push_back(i);
        if (func(temp_path) == -10) {    // signal meaning the solution ends the game- make a terminal node
            children.push_back(make_tree(func, 0, num_children, !is_minimum, temp_path));
        }
        else {
            children.push_back(make_tree(func, d-1, num_children, !is_minimum, temp_path));
        }
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

template<typename T>
void MMTree::print() {

    cout << "Minimax Tree:" << "\n=============\n\n";

    int num_tabs = 0;
    printTree(root, num_tabs);

    cout << "\n\n=============\n";
}

template <typename T>
void MMTree::printTree(Node* tree_root, int tabs) {
    // Print tabs
    for (int i = 0; i < tabs; i++)
        cout << "\t";
    
    // Print the path
    vector<int> temp_path = tree_root->getPath();
    cout << "[";
    for (int step : temp_path)
        cout << step << " ";
    cout << "]\n";

    // Print each of its children with one more tab
    for (Node* child : tree_root->getChildren())
        printTree(child, tabs - 1);
}

#endif