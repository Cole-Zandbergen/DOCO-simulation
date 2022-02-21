/*
    Source File for the Cell class
    Author: Cole Zandbergen
*/

#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y){
    xPos = x;
    yPos = y;
    //initialize the neighbors array?
    hasDOCO = false;
    numOfFoodPellets = 0;
}

Cell::~Cell(){
    delete neighbors;
}

void Cell::setNeighbors(Cell* newNeighbors[]){
    //have to loop and set each pointer in the neighbors array to the address of the corresponding index in the array that was passed in
    for(int i = 0; i < 8; i++){
        neighbors[i] = newNeighbors[i];
    }

    //neighbors = newNeighbors;
}