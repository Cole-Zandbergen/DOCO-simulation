/*
    This is the header file for the Movement Behavior interface.
    Author: Cole Zandbergen
*/
#pragma once
#include <string>
#include "Random.cpp"


class MovementBehavior{
public:
    MovementBehavior();
    ~MovementBehavior();
    virtual int generateDirection(int prev);
    virtual string display();
};