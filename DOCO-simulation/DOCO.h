#pragma once
/*
	Header file for the DOCO class
	This class contains all of the behaviors and information about the DOCOs in the simulation
	Author: Cole Zandbergen
*/

#include <iostream>
#include <fstream>
#include "Cell.h"
#include "MovementBehavior.h"

using namespace std;

class DOCO
{
private:
	int direction;
	Cell* cell;
	int energyLevel;
	MovementBehavior* mbeh;

public:
	DOCO(Cell* cell);
	~DOCO();
	void move();
	void eat();
	int sniff();
	//int generateDirection(int prev);
	void setDirection(int d);
	int getDirection();
	int getEnergyLevel();
	int getX();
	int getY();
	void setMovementBehavior(MovementBehavior* mbeh);
	DOCO* split();
	string display();
};