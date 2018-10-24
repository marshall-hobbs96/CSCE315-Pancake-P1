/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_AI.cpp - AI Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Player.h"
#include "../include/AI.h"

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "AI Test calculateMove 1", "[single-file]" ) {
    //int* stack = new int[4]{1, 2, 4, 3};
    AI tester(4, NULL, 1);
    int* solution = new int[4]{1, 2, 3, 4};
    int AImove = tester.calculateMove();
    CHECK( AImove == 2 );
    tester.makeMove(AImove);
    REQUIRE( tester.getStack()[2] == solution[2] );
}