/**
 * This is the implementation file for the vertical movement strategy
 * This file implements the functions to generate a direction and to display
 * Author: Cole Zandbergen
 */
#pragma once
#include "VerticalMovement.h"

int VerticalMovement::generateDirection(int prev){
    if (prev == 1) { //if the previous direction was north, we'll switch it to south
        return 5;
    }
    else if (prev == 5) {
        return 1;
    }
    else {
        int num = random(0, 1);
        return (num == 0 ? 1 : 5);
    }
}

string VerticalMovement::display() {
    return "|";
}