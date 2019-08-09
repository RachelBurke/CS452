// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Number_Command.h"
#include <iostream>

Number_Command::Number_Command (void) { }

Number_Command::Number_Command (int n): n_ (n) { }

Number_Command::~Number_Command (void) { }

bool Number_Command::execute (std::stack<int> & s)
{
    //Push the number onto the stack
    s.push (this -> n_);
    return true;
}

int Number_Command::precedence ()
{
    return -1;
}