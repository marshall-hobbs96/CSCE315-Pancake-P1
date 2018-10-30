/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_Player.cpp - Player Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Player.h"

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE( "Player Test makeMove 1", "[single-file]" ) {
    int* stack = new int[4]{1, 2, 4, 3};
    int* solution = new int[4]{1, 2, 3, 4};
    Player tester(4, stack, "Me");
    int move = 2;

    int original_size = tester.stack_size;
    tester.makeMove(move);
    int new_size = tester.stack_size;
    int* new_stack = tester.getStack();
    CHECK(original_size == new_size);

    for (int i = 0; i < tester.stack_size; i++) {
        REQUIRE(tester.getStack()[i] == solution[i]);
    }
}