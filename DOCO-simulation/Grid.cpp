/*
	Source file for the grid class
	Author: Cole Zandbergen
*/

#include "Grid.h"
#include <vector>
#include "Cell.h"

using namespace std;

//Default constructor
Grid::Grid(int width, int height) {

	//First, use this loop to create the grid vector
	for (int y = 0; y < height; y++) {
		vector<Cell*> temp; //initialize a new vector (couldn't find a better way to do this)
		Cells.push_back(temp);
		for (int x = 0; x < width; x++) {
			Cells.back().push_back(new Cell(x, y)); //add a new cell into the grid
		}
	}

	//Now, for each cell, we must give it its neighbor cells
	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width; c++) {
			//This will get complicated...
			//first, create a blank array
			Cell *neighbors[8];

			//start at neighbor 0
			//this will be the one at due north
			//we will move clockwise from there until we get all the way around

			if (r == 0) { //this is true if we are at the top of the grid
				neighbors[0] = nullptr;
				neighbors[1] = nullptr;
			}
			else { //if we are not at the top of the grid
				neighbors[0] = Cells.at(r - 1).at(c);

				//now, we can make sure that we are not on the right side of the grid
				if (c >= width - 1) {
					neighbors[1] = nullptr;
				}
				else { //so we are not on the top, or on the right side
					neighbors[1] = Cells.at(r - 1).at(c + 1);
				}
			}

			
		}
	}
}