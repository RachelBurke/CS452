// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <stack>

/**
 * @class Expr_Command
 * 
 * This abstract class that helps execute modifications on the stack
 */
class Command {

    public:

    /// Default Contructor
    Command (void) = default;

    /// Deconstructor
    virtual ~Command (void) = default;
	
    /// Execute function to be completed by Binary Operation
    virtual bool execute (std::stack<int> &s) = 0;

    //Precedence method to be implemented by Binary Ops/ Numbers/ Parens.
    virtual int precedence() = 0;
};


#endif
