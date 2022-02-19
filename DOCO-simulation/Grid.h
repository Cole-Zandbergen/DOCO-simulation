#pragma once
/*
	Header file for the Grid class
	This class will contain all of the cells that make up the DOCO world
	Author: Cole Zandbergen
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Cell.h"

using namespace std;

class Grid
{
private:
	vector<vector<Cell*> > Cells;
	
public:
	Grid(int width, int height);
	~Grid();
	string display();
	Cell* getCell();
	Cell* getCell(int x, int y);
	void addFoodPellets(int n);
};