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

/*
    move method
    Moves the DOCO in its correct direction
    First, this method makes sure that the DOCO will not try to enter a cell that cannot be entered
    If it is, then it changes direction randomly and tries again
    Then move the cell into the correct neighbor cell (corresponding to the cell's direction)
        *Don't forget to decrease the health by 10!
    Finally, the DOCO eats the food pellets from its new cell.
*/
void DOCO::move(){
    sniff();
    while(cell->getNeighbors(direction) == nullptr || (cell->getNeighbors(direction))->containsDOCO()){ 
        int newDirection = generateDirection(direction);
        setDirection(newDirection);
    }
    cell->removeDOCO();
    cell = cell->getNeighbors(direction);
    cell->addDOCO();
    energyLevel -= 10;
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

/*
    generateDirection method
    This method generates a random new direction for the DOCO to head in
    Takes in the previous direction to prevent duplicates
*/
int DOCO::generateDirection(int prev){
    int n = prev;
    while(n == prev){
        n = random(0, 7);
    }
    return n;
}

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