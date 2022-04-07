/*
    This file contains the implementation of the  movement behavior
    It will have methods to generate a new direction and to display the correct symbol
*/
#pragma once
//#include "MovementBehavior.h"
#include "HorizontalMovement.h"
//#include "Random.cpp"

HorizontalMovement::HorizontalMovement() {
    //This constructor is blank right now
}

int HorizontalMovement::generateDirection(int prev){
    if (prev == 7) {
        return 3;
    }
    else if (prev == 3) {
        return 7;
    }
    else {
        int num = random(0, 1);
        return (num == 0 ? 7 : 3);
    }
}

string HorizontalMovement::display(){
    return "=";
}