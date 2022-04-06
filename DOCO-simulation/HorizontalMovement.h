/**
 * This is the header file for the Horizontal Movement behavior class
 * Author: Cole Zandbergen
 */

#include "MovementBehavior.h"

class HorizontalMovement : public MovementBehavior {
    public:
        HorizontalMovement();
        int generateDirection(int prev);
        char display();
};