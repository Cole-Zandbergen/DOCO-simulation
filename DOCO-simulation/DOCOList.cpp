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

/*
    update method
    This method will loop through each DOCO and update it.
    This method will return a string containing information about each DOCO.
    Information is added into the string on each iteration of the loop.
*/
string DOCOList::update(){
    string status = "";
    for(int i = 0; i < DOCOs.size(); i++){
        DOCO* currentDOCO = DOCOs[i];
        if(currentDOCO->getEnergyLevel() <= 0){
            delete DOCOs[i]; //this might cause problems.... but i believe it is necessary because erase() will not delete
            //once we have destroyed the DOCO itself, let's remove it from the vecctor
            DOCOs.erase(DOCOs.begin() + i);
            continue;
        }
        else{
            DOCOs[i]->move();
        }
        //add in information about the DOCO for the output files
        status += "DOCO number " + to_string(i) + ":\n";
        status += "\tDirection: " + to_string(DOCOs[i]->getDirection());
        status += "\n\tEnergy Level: " + to_string(DOCOs[i]->getEnergyLevel()) + "\n";
    }
    
    return status;
}

//Add a DOCO to the list
void DOCOList::addDOCO(DOCO* d){
    DOCOs.push_back(d);
}

//Gets the size of the list (number of DOCOs that are alive)
int DOCOList::getSize(){
    return DOCOs.size();
}