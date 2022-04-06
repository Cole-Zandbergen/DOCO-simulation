/*
    This file contains the implementation of the  movement behavior
    It will have methods to generate a new direction and to display the correct symbol
*/

#include "HorizontalMovement.h"

int HorizontalMovement::generateDirection(int prev){
    int num = random(0, 1);
    if(num == 0){
        return 7; //west
    }
    else{
        return 3; //east
    }
}

char display(){
    return '=';
}