#pragma once
/*
	Header file for the Cell class
	Each instance of this class represents one block on the Grid of the DOCO world
	Author: Cole Zandbergen
*/

#include <iostream>
#include <fstream>

using namespace std;

class Cell
{
private:
	int xPos;
	int yPos;
	int numOfFoodPellets;
	bool hasDOCO;
	Cell* neighbors[8];

public:
	Cell(int x, int y);
	~Cell();
	void setNeighbors(Cell* newNeighbors[]);
	Cell* getNeighbor(int n);
	char display();
	void addDOCO();
	void removeDOCO();
	void addFood();
	void removeFood();
	int getxPos();
	int getyPos();
	int getNumOfFoodPellets();
};