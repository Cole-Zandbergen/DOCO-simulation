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
			
			//first, create a blank array
			Cell *neighbors[8] = {nullptr};

			//start at neighbor 0
			//this will be the one at due north
			//we will move clockwise from there until we get all the way around

			try{
				neighbors[0] = Cells.at(r-1).at(c-1); //northwest
			}
			catch(const out_of_range& e){
				neighbors[0] = nullptr;
			}


			try{
				neighbors[1] = Cells.at(r-1).at(c); //due north
			}
			catch(const out_of_range& e){
				neighbors[1] = nullptr;
			}

			try{
				neighbors[2] = Cells.at(r-1).at(c+1); //northeast
			}
			catch(const out_of_range& e)
			{
				neighbors[2] = nullptr;
			}

			try{
				neighbors[3] = Cells.at(r).at(c+1); //due east
			}
			catch(const out_of_range& e){
				neighbors[3] = nullptr;
			}

			try{
				neighbors[4] = Cells.at(r+1).at(c+1); //southeast
			}
			catch(const out_of_range& e){
				neighbors[4] = nullptr;
			}

			try{
				neighbors[5] = Cells.at(r+1).at(c); //due south
			}
			catch(const out_of_range& e){
				neighbors[5] = nullptr;
			}

			try{
				neighbors[6] = Cells.at(r+1).at(c-1); //southwest
			}
			catch(const out_of_range& e){
				neighbors[6] = nullptr;
			}

			try{
				neighbors[7] = Cells.at(r).at(c-1);
			}
			catch(const out_of_range& e){
				neighbors[7] = nullptr;
			}
			
		}
	}
}