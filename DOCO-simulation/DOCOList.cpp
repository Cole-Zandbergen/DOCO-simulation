/*
    Implementation file for the DOCOList class
    Author: Cole Zandbergen
*/

#include "DOCOList.h"
#include <string>

using namespace std;


//Default constructor
DOCOList::DOCOList(){
    
}

//Default destructor
DOCOList::~DOCOList(){
    DOCOs.clear();
}

string DOCOList::update(){
    string status = "";
    for(int i = 0; i < DOCOs.size(); i++){
        DOCO* currentDOCO = DOCOs[i];
        if(currentDOCO->getEnergyLevel() <= 0){
            delete DOCOs[i]; //this might cause problems.... but i believe it is necessary because erase() will not delete
            DOCOs.erase(DOCOs.begin()+5);
        }
        else{
            DOCOs[i]->move();
        }
        status += "DOCO number " + to_string(i) + ":\n";
        status += "\tDirection: " + to_string(DOCOs[i]->getDirection());
        status += "\n\tEnergy Level: " + to_string(DOCOs[i]->getEnergyLevel()) + "\n";
    }
    
    return status;
}

void DOCOList::addDOCO(DOCO* d){
    DOCOs.push_back(d);
}

int DOCOList::getSize(){
    return DOCOs.size();
}