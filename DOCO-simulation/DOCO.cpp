/*
    Implementation file for the DOCO class
    Author: Cole Zandbergen
*/

#include "DOCO.h"
#include "Cell.h"

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