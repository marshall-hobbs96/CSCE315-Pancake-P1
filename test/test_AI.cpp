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
    // Testing minimax tree search at depth 1
    int* stack = new int[6]{5, 6, 1, 4, 3, 2};
    AI tester(6, stack, 1);
    int solution = 3;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[6]{5, 6, 1, 2, 3, 4};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[i] == new_stack[i]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}

TEST_CASE( "AI Test calculateMove 2", "[single-file]" ) {
    // Testing minimax tree search at depth 2
    int* stack = new int[3]{1, 3, 2};
    AI tester(3, stack, 2);
    int solution = 1;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[3]{1, 2, 3};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[i] == new_stack[i]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}

TEST_CASE( "AI Test calculateMove 3", "[single-file]" ) {
    // Testing minimax tree search at depth 3
    int* stack = new int[3]{3, 1, 2};
    AI tester(3, stack, 3);
    int solution = 1;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[3]{3, 2, 1};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[i] == new_stack[i]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}

TEST_CASE( "AI Test calculateMove 4", "[single-file]" ) {
    // Testing minimax tree search at depth 3
    int* stack = new int[4]{1, 3, 4, 2};
    AI tester(4, stack, 4);
    int solution = 1;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[4]{1, 2, 4, 3};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[i] == new_stack[i]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}

TEST_CASE( "AI Test calculateMove 5", "[single-file]" ) {
    // Testing minimax tree search at depth 5
    int* stack = new int[9]{1, 2, 3, 4, 5, 6, 7, 9, 8};
    AI tester(9, stack, 5);
    int solution = 7;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[9]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[i] == new_stack[i]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}

TEST_CASE( "AI Test calculateMove 6", "[single-file]" ) {
    // Testing minimax tree search when in reverse order
    int* stack = new int[5]{1, 2, 3, 4, 5};
    AI tester(5, stack, 5);
    int solution = 0;
    int AImove = tester.calculateMove();
    CHECK( AImove == solution );

    int* new_stack = new int[5]{5, 4, 3, 2, 1};
    tester.makeMove(AImove);

    for (int i =0; i < tester.getStackSize(); i++) {
        CHECK(tester.getStack()[i] == new_stack[i]);
    }

    delete[] stack;
    delete[] new_stack;
    REQUIRE( true );
}