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
	bool obstacle;
	string DOCOsymbol;

public:
	Cell(int x, int y);
	~Cell();
	void setNeighbors(Cell* newNeighbors[]);
	string display();
	void addDOCO(string s);
	void removeDOCO();
	void addFood();
	void removeFood();
	int getxPos();
	int getyPos();
	int getNumOfFoodPellets();
	Cell* getNeighbors(int i);
	bool containsDOCO();
	void setObstacle();
	bool isObstacle();
};