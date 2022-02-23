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

}

void DOCO::move(){
    sniff();
    while(cell->getNeighbors() + direction == nullptr || (cell->getNeighbors() + direction)->containsDOCO()){ // pointer arithmetic... may need to change this (just make this a friend class as a last resort)
        cout << "DOCO has to change direction" << endl;
        int newDirection = generateDirection(direction);
        setDirection(newDirection);
    }
    cell = cell->getNeighbors() + direction; //more pointer arithmetic ... this scares me
    energyLevel -= 10;
    eat();
}

void DOCO::eat(){
    energyLevel += 50*cell->getNumOfFoodPellets();
    cout << "DOCO is eating " << cell->getNumOfFoodPellets() << " food pellets at cell location (" << cell->getxPos() << ", " << cell->getyPos() << ")" << endl;
    cell->removeFood();
    //eat the food and then tell the cell that all of its food is gone
    //this works even when there is no food in the cell
}

void DOCO::sniff(){
    for(int i = 0; i < 8; i++){
        if(((cell->getNeighbors() + i)->getNumOfFoodPellets()) > 0){ //if there is a food pellet in the cell
            setDirection(i); //set the DOCO to head towards the food
            break; //end the loop because we already found the food
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