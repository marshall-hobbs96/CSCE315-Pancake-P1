/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

Node.h - Interface for the Node class of a minimax tree
*/

#ifndef __NODE__        // For #including more than once
#define __NODE__

/************************************************
 *  INCLUDES
 ***********************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;


/************************************************
 * Main Class
 ***********************************************/

class Node {
private:
    vector<Node*> children;
    bool is_min;
    int value;
    vector<int> path;          // path to the node
public:
    Node(vector<Node*> kids, bool im, int init_val, vector<int> curr_path);
    ~Node();
    Node* eval();
    vector<Node*> getChildren();
    int getValue();
    vector<int> getPath();
};

#endif