// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Subtract_Command.h"

Subtract_Command::Subtract_Command (void) { }

Subtract_Command::~Subtract_Command (void) { }

int Subtract_Command::evaluate (int n1, int n2){
    //Return the result of subtracting n1 and n2
    return n1 - n2;
}

int Subtract_Command::precedence ()
{
    return 1;
}
