/*
	This is the implementation for the DiagonalMovement class
	This file will implement the methods to generate a new direction and to display the DOCO
	Author: Cole Zandbergen
*/
#pragma once
#include "DiagonalMovement.h"
#include <string>
//#include "Random.cpp"

int DiagonalMovement::generateDirection(int prev) {
	int num;
	do {
		num = random(0, 3);
	} while (num * 2 == prev);
		return num * 2;
}

string DiagonalMovement::display() {
	return "X";
}