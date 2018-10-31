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
    // Testing one level deep with min root
    
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
    
    // No Cleanup necessary
    REQUIRE(true);
}

TEST_CASE( "Node Test eval 2", "[single-file]" ) {
    // Testing one level deep with max root
    
    // Set up tester and solution
    vector<Node*> empty_kids, kids;

    // Max leaves
    Node* node1 = new Node(empty_kids, true, 1);
    kids.push_back(node1);
    Node* node2 = new Node(empty_kids, true, 2);
    kids.push_back(node2);
    Node* node3 = new Node(empty_kids, true, 3);
    kids.push_back(node3);

    // Min root
    Node root(kids, false, 0);

    int value = root.eval();

    CHECK(value == 3);
    
    // No Cleanup necessary
    REQUIRE(true);
}