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
#include <assert.h>

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/

//test score calculation
if(false)
{
    cout<<"Case1: Test AI Sorted & User stack not sorted"<<endl;
    int difficulty = 4;
    int n = 5;
    int[] ai = {5,4,3,2,1};
    int[] user = {1,3,4,5,2};
    assert(Game::computeScore(user*, ai*, difficulty)==n);
    cout<<"Case 1 passed"<<endl;
  
    cout<<"Case2: Test AI Sorted & User stack sorted"<<endl;
    difficulty = 4;
    n = 5;
    ai = {5,4,3,2,1};
    user = {5,4,3,2,1};
    assert(Game::computeScore(user*, ai*, difficulty)==(n*(difficulty+1)));
    cout<<"Case 2 passed"<<endl;
           
    cout<<"Case3: Test AI not Sorted & User stack sorted"<<endl;
    difficulty = 4;
    n = 5;
    ai = {5,3,4,2,1};
    user = {5,4,3,2,1};
    assert(Game::computeScore(user*, ai*, difficulty)==(2*n*(difficulty+1)));
    cout<<"Case 3 passed"<<endl;
  
    cout<<"Case4: Test AI not Sorted & User stack not sorted"<<endl;
    difficulty = 4;
    n = 5;
    ai = {5,3,4,2,1};
    user = {5,4,3,1,2};
    assert(Game::computeScore(user*, ai*, difficulty)==-1);
    cout<<"Case 4 passed"<<endl;
}
