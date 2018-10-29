/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

AI.cpp - AI implementation for calculating the next move
*/

#include "AI.h"

AI::AI(int num_pancakes, int* order, int diff) :
    Player(num_pancakes, order, ""), difficulty(diff) {}

int AI::calculateMove() {
    // Construct a minimax tree
    MMTree minimax_tree(stack, difficulty);
    // Evaluate it
    int choice = minimax_tree.eval();
    // Collect Garbage
    // Return the result
    return choice;
}