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
    //^^can't do that because arrays are not modifiable??
}

string Cell::display(){
    if(hasDOCO){
        return "*";
    }
    else if(numOfFoodPellets > 0){
        return ".";
    }
    else{
        return "-";
    }
}

void Cell::addDOCO(){
    hasDOCO = true;
}

void Cell::removeDOCO(){
    hasDOCO = false;
}

void Cell::addFood(){
    numOfFoodPellets++;
}

void Cell::removeFood(){
    numOfFoodPellets = 0;
}

int Cell::getxPos(){
    return xPos;
}

int Cell::getyPos(){
    return yPos;
}

int Cell::getNumOfFoodPellets(){
    return numOfFoodPellets;
}

Cell* Cell::getNeighbors(){
    return neighbors[0];
}

bool Cell::containsDOCO(){
    return hasDOCO;
}