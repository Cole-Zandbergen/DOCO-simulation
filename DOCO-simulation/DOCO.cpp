/*
    Implementation file for the DOCO class
    Author: Cole Zandbergen
*/

#include "DOCO.h"
#include "Cell.h"
#include "Random.cpp"

using namespace std;


//Default constructor
DOCO::DOCO(Cell* c){
    direction = generateDirection(-1); //prev is -1 because there is no previous
    cell = c;
    energyLevel = 500;
}

//Default destructor
DOCO::~DOCO(){
    //remove this DOCO from its cell
    cell->removeDOCO();
}

void DOCO::move(){
    sniff();
    while(cell->getNeighbors(direction) == nullptr || (cell->getNeighbors(direction))->containsDOCO()){ 
        //cout << "DOCO has to change direction" << endl;
        int newDirection = generateDirection(direction);
        setDirection(newDirection);
    }
    cell->removeDOCO();
    cell = cell->getNeighbors(direction);
    cell->addDOCO();
    energyLevel -= 10;
    eat();
}

void DOCO::eat(){
    energyLevel += 50*cell->getNumOfFoodPellets();
    cell->removeFood();
    //eat the food and then tell the cell that all of its food is gone
    //this works even when there is no food in the cell
}

void DOCO::sniff(){
    for(int i = 0; i < 8; i++){
        if ((cell->getNeighbors(i))) { //make sure the cell exists
            if (((cell->getNeighbors(i))->getNumOfFoodPellets()) > 0) { //if there is a food pellet in the cell
                setDirection(i); //set the DOCO to head towards the food
                break; //end the loop because we already found the food
            }
        }
    }
}

int DOCO::generateDirection(int prev){
    int n = prev;
    while(n == prev){
        n = random(0, 7);
    }
    return n;
}

void DOCO::setDirection(int d){
    direction = d;
}

int DOCO::getEnergyLevel() {
    return energyLevel;
}

int DOCO::getDirection() {
    return direction;
}