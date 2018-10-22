/*
CSCE 315 503
Project 3
Group 17

Abdul Campos
Marshall Hobbs
McLain Johnson
Troy Fulton

Player.cpp - Implementations for Player class (making moves, returning the stack, etc.)
*/

#include "Player.h"

Player::Player(int num_pancakes, int* order, std::string un) :
    stack_size(num_pancakes), stack(order), username(un) {}

int* Player::getStack() {
    // Implementation...
    return stack;
}

void Player::makeMove(int pancake) {
    // Implementation...
    stack = new int[4]{1, 2, 3, 4};
}