// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "BinaryOperation_Command.h"
#include <iostream>

BinaryOperation_Command::BinaryOperation_Command (void) { }

BinaryOperation_Command::~BinaryOperation_Command (void) { }

bool BinaryOperation_Command::execute (std::stack<int> & s)
{
    //Nothing possible to execute so return false
    if(s.empty())
        return false;

    //Get the first number to pop and take it off the stack
    int n1 = s.top();
    s.pop();
    //Get the second number to pop and take it off the stack
    int n2 = s.top();
    s.pop();
    //Evaluate the two numbers together and push the result onto the stack
    s.push(this -> evaluate(n2, n1));

    return true;
}
