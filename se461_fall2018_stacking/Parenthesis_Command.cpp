// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Parenthesis_Command.h"

Parenthesis_Command::Parenthesis_Command (void): Command() { }

Parenthesis_Command::~Parenthesis_Command (void) { }

bool Parenthesis_Command::execute (std::stack<int> &s)
{
    //Comment: Yes, I admit this is code rot, however, this 
    //Can be used later to implement "()" as multiplication later if needed
    //Nothing to do it is a parenthesis
    return true;
}

int Parenthesis_Command::precedence ()
{
    return 0;
}