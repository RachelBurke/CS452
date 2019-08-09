// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Modular_Command.h"

Modular_Command::Modular_Command (void): BinaryOperation_Command() { }

Modular_Command::~Modular_Command (void) { }

int Modular_Command::evaluate (int n1, int n2)
{
    try
    {
        if (n2 == 0)
            throw Modular_By_Zero();

        //Return the modular result of n1 and n2
        return n1 % n2;
    }
    catch (std::exception e)
    {
        e.what();
    }
}

int Modular_Command::precedence ()
{
    return 2;
}