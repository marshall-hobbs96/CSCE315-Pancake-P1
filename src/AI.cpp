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
    // Implementation...
    return 2;
}

int AI::getDifficulty()
{
	return this->difficulty;
}