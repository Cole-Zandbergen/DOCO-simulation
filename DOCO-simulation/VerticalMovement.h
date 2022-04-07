/**
 * This is the header file for the VerticalMovement class
 * Author: Cole Zandbergen
 */
#pragma once
#include "MovementBehavior.h"

class VerticalMovement : public MovementBehavior{
    public:
        int generateDirection(int prev);
        string display();
};