// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Divide_Command.h"

Divide_Command::Divide_Command (void): BinaryOperation_Command() { }

Divide_Command::~Divide_Command (void) { }

int Divide_Command::evaluate (int n1, int n2)
{
    //Making sure not dividing by zero
    if(n2 == 0)
        throw Divide_By_Zero();

    //Return the division of n1 and n2
    return n1 / n2;
}

int Divide_Command::precedence ()
{
    return 2;
}