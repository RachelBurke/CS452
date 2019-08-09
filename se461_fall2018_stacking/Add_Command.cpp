// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Add_Command.h"

Add_Command::Add_Command (void): BinaryOperation_Command() { }

Add_Command::~Add_Command (void) { }

int Add_Command::evaluate (int n1, int n2)
{
    //Return the sum of n1 and n2
    return n1 + n2;
}

int Add_Command::precedence()
{
    return 1;
}

