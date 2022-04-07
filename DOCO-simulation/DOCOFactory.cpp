/*
    Implementation file for the singleton class DOCOFactory
    Author: Cole Zandbergen
*/
#pragma once
#include "DOCOFactory.h"
#include "Cell.h"
#include "DOCO.h"
#include "MovementBehavior.h"
#include "HorizontalMovement.h"
#include "VerticalMovement.h"
#include "DiagonalMovement.h"

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

DOCO* DOCOFactory::createDOCO(Cell* cell, string type){
    //You can't do a switch statement on a string.... so I will have to just use if/else 
    DOCO* d = new DOCO(cell);

    if(type.compare("HORIZONTAL") == 0) {
        MovementBehavior* mbeh = new HorizontalMovement();
        d->setMovementBehavior(mbeh);
        d->setDirection(mbeh->generateDirection(-1));
        return d;
    } else if(type.compare("VERTICAL") == 0) {
        MovementBehavior* mbeh = new VerticalMovement();
        d->setMovementBehavior(mbeh);
        d->setDirection(mbeh->generateDirection(-1));
        return d;
    } else {
        MovementBehavior* mbeh = new DiagonalMovement();
        d->setMovementBehavior(mbeh);
        d->setDirection(mbeh->generateDirection(-1));
        return d;
    }
}