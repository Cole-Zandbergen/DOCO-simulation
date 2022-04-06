#pragma once
/*
	Header file for the World class
	this class will drive the simulation and contain all of its elements
	Author: Cole Zandbergen
*/

#include <iostream>
#include <fstream>
#include "Grid.h"
#include "DOCOList.h"

using namespace std;

class World
{
private:
	Grid* map;
	DOCOList* DOCOs;

public:
	World(const char* filename);
	~World();
	Grid* createGrid(int height, int width);
	void addDOCO(int xPos, int yPos, char type);
	string update();
	DOCOList* getDOCOs();
};