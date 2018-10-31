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

int Player::getStackSize() {
    return stack_size;
}

void Player::swapPancakes(int i, int j) {
    int temp_pancake = stack[i];
    stack[i] = stack[j];
    stack[j] = temp_pancake;
}

void Player::makeMove(int pancake) {
    // Count of pancakes at and above spatula
    int pancakes_to_flip = (stack_size - pancake)/2;
    
    // If we need to look at more than one
    if (pancakes_to_flip >= 1) {
        
        // For each of the pancakes above the spatula
        for (int i = pancake; i < pancake + (pancakes_to_flip/2) + 1; i++) {
            swapPancakes(i, stack_size - i + pancake - 1);
        }
    }
    
    return;
}

void Player::setName(std::string name) {
     username = name;
 }