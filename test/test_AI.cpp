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
    // Testing minimax tree search at depth 2
    int* stack = new int[3]{1, 3, 2};
    AI tester(3, stack, 2);
    int solution = 1;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[3]{1, 2, 3};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[2] == solution[2]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}