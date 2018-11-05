/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

test_Game.cpp - Game Unit Testing
*/

/****************************************************
 * INCLUDES
 ***************************************************/

#include "includecatch2.cpp"
#include "../include/Game.h"
#include <iostream>
#include <array>

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

TEST_CASE("Case1: Test AI Sorted & User stack not sorted")
{
	int difficulty = 4;
	int n = 5;
	int ai[] = {5,4,3,2,1};
	int user[] = {1,3,4,5,2};
	Game g(n, difficulty, "scores.txt", NULL);

	CHECK(g.computeScore(difficulty, n, user, ai)==n);
}
TEST_CASE("Case2: Test AI Sorted & User stack sorted")
{
  difficulty = 4;
  n = 5;
  int ai1[] = {5,4,3,2,1};
  int user1[] = {5,4,3,2,1};
  Game g(n, difficulty, "scores.txt", NULL);

  CHECK(computeScore(difficulty,n ,user1, ai1)==(n*(difficulty+1)));
}

TEST_CASE("Case3: Test AI not Sorted & User stack sorted")
{
  difficulty = 4;
  n = 5;
  int ai2[] = {5,3,4,2,1};
  int user2[] = {5,4,3,2,1};
  Game g(n, difficulty, "scores.txt", NULL);
  CHECK(computeScore(difficulty,n ,user2, ai2)==(2*n*(difficulty+1)));
}

TEST_CASE("Case4: Test AI not Sorted & User stack not sorted"){
  difficulty = 4;
  n = 5;
  int ai3[] = {5,3,4,2,1};
  int user3[] = {5,4,3,1,2};
  Game g(n, difficulty, "scores.txt", NULL);
  CHECK(computeScore(difficulty,n ,user3, ai3)==-1);
}


TEST_CASE("Testing whether pancakeStack in int form converts to string successfully. stackToString"){

    int stackSize = 9;
    int* stack = new int[stackSize]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::string stringStack = stackToString(stack, stackSize);
    correctStack = "+-+/n|1|/n+-+/n+---+/n| 2 |/n+---+/n+-----+/n|  3  |/n+-----+/n+-------+/n|   4   |/n+-------+/n+---------+/n|    5    |/n+---------+/n+-----------+/n|     6     |/n+-----------+/n+-------------+/n|      7      |/n+-------------+/n+---------------+/n|       8       |/n+---------------+/n+-----------------+/n|        9        |/n+---------------+/n";

    CHECK(stringStack == correctStack);

    delete stack;

}
