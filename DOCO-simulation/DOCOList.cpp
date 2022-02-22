/*
    Implementation file for the DOCOList class
    Author: Cole Zandbergen
*/

#include "DOCOList.h"

using namespace std;


//Default constructor
DOCOList::DOCOList(){
    
}

//Default destructor
DOCOList::~DOCOList(){
    DOCOs.clear();
}

void DOCOList::update(){
    for(int i = 0; i < DOCOs.size(); i++){
        DOCO* currentDOCO = DOCOs[i];
        if(currentDOCO->getEnergyLevel() <= 0){
            delete DOCOs[i]; //this might cause problems.... but i believe it is necessary because erase() will not delete
            DOCOs.erase(DOCOs.begin()+5);
        }
        else{
            DOCOs[i]->move();
        } 
    }
}

void DOCOList::addDOCO(DOCO* d){
    DOCOs.push_back(d);
}