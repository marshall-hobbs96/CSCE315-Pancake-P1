/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_Node.cpp - Minimax Tree Node Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Node.h"

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "Node Test eval 1", "[single-file]" ) {
    // Testing odd number size stack
    
    // Set up tester and solution
    vector<Node*> empty_kids, kids;

    // Max leaves
    Node* node1 = new Node(empty_kids, false, 1);
    kids.push_back(node1);
    Node* node2 = new Node(empty_kids, false, 2);
    kids.push_back(node2);
    Node* node3 = new Node(empty_kids, false, 3);
    kids.push_back(node3);

    // Min root
    Node root(kids, true, 0);

    int value = root.eval();

    CHECK(value == 1);
    
    // Cleanup
    /*
    delete node1;
    delete node2;
    delete node3;
    */
    REQUIRE(true);
}