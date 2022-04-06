/**
 * This is the header file for the VerticalMovement class
 * Author: Cole Zandbergen
 */

class VerticalMovement : public MovementBehavior{
    public:
        int generateDirection(int prev);
        char display();
};