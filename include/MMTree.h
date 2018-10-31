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

#endif