//This is the header file for the DOCOFactory class
#pragma once
#include "Cell.h"
#include "DOCO.h"

class DOCOFactory
{
    private:
        DOCOFactory();
    public:
        ~DOCOFactory();
        DOCOFactory* getInstance();
        DOCO* createDOCO(Cell* cell, string type);
};