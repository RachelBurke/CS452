// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Multiply_Command.h"
#include <iostream>

Multiply_Command::Multiply_Command (void): BinaryOperation_Command() { }

Multiply_Command::~Multiply_Command (void) { }

int Multiply_Command::evaluate (int n1, int n2){
    //Return the product of n1 and n2
    return n1 * n2;
}

int Multiply_Command::precedence ()
{
    return 2;
}