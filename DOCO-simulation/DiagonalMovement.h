/*
	This is the header file for the Diagonal Movement strategy
	Author: Cole Zandbergen
*/
#pragma once
#include "MovementBehavior.h"

class DiagonalMovement : public MovementBehavior
{
public:
	int generateDirection(int prev);
	string display();
};