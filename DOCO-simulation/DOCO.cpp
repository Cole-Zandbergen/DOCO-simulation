/*
    Implementation file for the DOCO class
    Author: Cole Zandbergen
*/
#pragma once
#include "DOCO.h"
#include "Cell.h"
//#include "Random.cpp"

using namespace std;


//Default constructor
DOCO::DOCO(Cell* c){
    //direction = mbeh->generateDirection(-1); //prev is -1 because there is no previous
    cell = c;
    energyLevel = 500;
}

//Default destructor
DOCO::~DOCO(){
    //remove this DOCO from its cell
    cell->removeDOCO();
}

/*
    move method
    Moves the DOCO in its correct direction
    First, this method makes sure that the DOCO will not try to enter a cell that cannot be entered
    If it is, then it changes direction randomly and tries again
    Then move the cell into the correct neighbor cell (corresponding to the cell's direction)
        *Don't forget to decrease the health by 25!
    Finally, the DOCO eats the food pellets from its new cell.
*/
void DOCO::move(){
    int s = sniff();
    if(s == -1){
        while (cell->getNeighbors(direction) == nullptr || (cell->getNeighbors(direction))->containsDOCO() || cell->getNeighbors(direction)->isObstacle()) {
            int newDirection = mbeh->generateDirection(direction);
            setDirection(newDirection);
        }
        cell->removeDOCO();
        cell = cell->getNeighbors(direction);
        cell->addDOCO(mbeh->display());
    }
    else {
        cell->removeDOCO();
        cell = cell->getNeighbors(s);
        cell->addDOCO(mbeh->display());
    }
    energyLevel -= 25;
    eat();
}

/*
    eat method
    This method will eat the food and then tell the cell that all of its food is gone.
    This works even when there is no food in the cell.
*/
void DOCO::eat(){
    energyLevel += 50*cell->getNumOfFoodPellets();
    cell->removeFood();
}

/*
    sniff method
    This method will check for food in any of the DOCO's neighboring cells.
*/
int DOCO::sniff(){
    for(int i = 0; i < 8; i++){
        if ((cell->getNeighbors(i))) { //make sure the cell exists
            if (((cell->getNeighbors(i))->getNumOfFoodPellets()) > 0) { //if there is a food pellet in the cell
                return i; //return the place we need to go 
            }
        }
    }
    return -1;
}

/*
    generateDirection method
    This method generates a random new direction for the DOCO to head in
    Takes in the previous direction to prevent duplicates
*
int DOCO::generateDirection(int prev){
    int n = prev;
    while(n == prev){
        n = random(0, 7);
    }
    return n;
}*/

//Sets the direction to a new number
void DOCO::setDirection(int d){
    direction = d;
}

//Gets the DOCO's energy level
int DOCO::getEnergyLevel() {
    return energyLevel;
}

//Gets the DOCO's direction
int DOCO::getDirection() {
    return direction;
}

//Gets the DOCO's x coordinate
int DOCO::getX() {
    return cell->getxPos();
}

//Gets the DOCO's y coordinate
int DOCO::getY() {
    return cell->getyPos();
}

//Method to set the movement behavior of the DOCO
void DOCO::setMovementBehavior(MovementBehavior* b)
{
    mbeh = b;
}

//Method to split the DOCO into two identical DOCOs
DOCO* DOCO::split()
{
    energyLevel /= 2;
    DOCO* twin = new DOCO(cell);
    twin->setMovementBehavior(mbeh);
    twin->energyLevel = energyLevel;
    return twin;
}

string DOCO::display() {
    return mbeh->display();
}