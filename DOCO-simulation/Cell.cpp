/*
    Source File for the Cell class
    Author: Cole Zandbergen
*/
#pragma once
#include "Cell.h"
using namespace std;

//Constructor method
Cell::Cell(int x, int y){
    xPos = x;
    yPos = y;
    hasDOCO = false;
    numOfFoodPellets = 0;
    obstacle = false;
    DOCOsymbol = "-";
}

//Destructor method
Cell::~Cell(){
    delete neighbors;
}

/*
    Set neighbors: takes a pointer to an array of cells
    This method loops through that array and sets each individual element equal to what was in the first array.
*/
void Cell::setNeighbors(Cell* newNeighbors[]){
    for(int i = 0; i < 8; i++){
        neighbors[i] = newNeighbors[i];
    }
}

/*
    Display method:
    Returns nothing but a character indicating what this cell contains. 
    The options are:
        1) A DOCO
        2) An obstacle
        2) A Food Pellet
        3) Nothing
*/
string Cell::display(){
    if(hasDOCO){
        return DOCOsymbol;
    }
    else if (obstacle) {
        return "\xb2";
    }
    else if(numOfFoodPellets > 0){
        return ".";
    }
    else{
        return "-";
    }
}

/*
    addDOCO method
    Will be called when a DOCO enters the cell.
    Used to indicate to the cell that there is a DOCO inside of it now.
*/
void Cell::addDOCO(string s){
    hasDOCO = true;
    DOCOsymbol = s;
}

/*
    removeDOCO method
    Does the opposite of the above method.
*/
void Cell::removeDOCO(){
    hasDOCO = false;
    DOCOsymbol = "-";
}

/*
    addFood method
    Called only when the cell has less than 3 pellets in it
    Will increase the amount of food currently in the cell 
*/
void Cell::addFood(){
    numOfFoodPellets++;
}

/* 
    removeFood method
    This is called when the DOCO eats.
    This method will set the amount of food to 0
*/
void Cell::removeFood(){
    numOfFoodPellets = 0;
}

//Gets the cell's x position.
int Cell::getxPos(){
    return xPos;
}

//Gets the cell's y position
int Cell::getyPos(){
    return yPos;
}

//Gets the number of food pellets that are currently in the cell
int Cell::getNumOfFoodPellets(){
    return numOfFoodPellets;
}

/*
    getNeighbors method
    This method returns one neighbor at a specific index
    Called when a DOCO tries to move
    ex: if the DOCO's direction is 1, it will call getNeighbors(1) to move into the cell's neighbor
*/
Cell* Cell::getNeighbors(int i){
    return neighbors[i];
}

//Returns whether or not there is a DOCO in the cell
bool Cell::containsDOCO() {
    return hasDOCO;
}

void Cell::setObstacle() {
    obstacle = true;
}

bool Cell::isObstacle() {
    return obstacle;
}