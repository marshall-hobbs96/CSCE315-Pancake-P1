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
using namespace std;

AI::AI(int num_pancakes, int* order, int diff) :
    Player(num_pancakes, order, ""), difficulty(diff) {}

int AI::calculateMove() {
    Helper h;
    MMTree<Helper> mmt(h, difficulty, stack_size);
    return mmt.bestMove();
}

// Utility function:
int AI::Helper::operator()(vector<int> path) {
    // Get initial sortedness
    int init_sortedness = getSortedness();

    // Do all the flips in order
    for (int move : path) {
        makeMove(move);
    }

    // Get the sortedness difference
    int score = getSortedness() - init_sortedness;

    // Put the stack back where you found it (do the flips in reverse order)
    for (int i = path.size() - 1; i >= 0; i--) {
        makeMove(path[i]);
    }

    return score;
}