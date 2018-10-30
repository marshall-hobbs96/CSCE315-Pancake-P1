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

class MMTree {
private:
    Node* root;
    int depth;
    int utility(int* stack);

public:
    MMTree(int* stack, int d);
    ~MMTree();
    int eval();
};

#endif