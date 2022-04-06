/*
    Implementation file for the singleton class DOCOFactory
    Author: Cole Zandbergen
*/

#include "DOCOFactory.h"
#include "Cell.h"
#include "DOCO.h"
#include "MovementBehavior.h"
#include "HorizontalMovement.h"

using namespace std;

//Default constructor method
DOCOFactory::DOCOFactory(){

}

//Default destructor method
DOCOFactory::~DOCOFactory(){

}

//getInstance method - will return the one and only possible instance of DOCOFactory
DOCOFactory* DOCOFactory::getInstance(){
    static DOCOFactory* theInstance;
    if(theInstance == nullptr){
        theInstance = new DOCOFactory();
    }

    return theInstance;
}

DOCO* createDOCO(Cell* cell, char* type){
    //You can't do a switch statement on a string.... so I will have to just use if/else 
    DOCO* d = new DOCO(cell);

    if(strcmp(type, "HORIZONTAL") == 0){
        d->setMovementBehavior(new MovementBehavior());
        return d;
    } else if(strcmp(type, "VERTICAL") == 0){
        d->setMovementBehavior(new VerticalMovement());
    }
}