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

/****************************************************
 * DEFINES
 ***************************************************/

/****************************************************
 * TEST CASES
 ***************************************************/
 
 TEST_CASE( "Given no file, should return """, "[Game.cpp]" ) 
 {
	 REQUIRE(findScore("") == "");
	 REQUIRE(getHighScore() == "");
 }