#pragma once
/*
	Header file for the DOCO class
	This class contains all of the behaviors and information about the DOCOs in the simulation
	Author: Cole Zandbergen
*/

#include <iostream>
#include <fstream>
#include "Cell.h"

using namespace std;

class DOCO
{
private:
	int direction;
	Cell* Cell;
	int energyLevel;

public:
	DOCO();
	~DOCO();
	void move();
	void eat();
	void sniff();
	int generateDirection(int prev);
	int setDirection();
	int getDirection();
};