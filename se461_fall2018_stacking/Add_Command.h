// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "BinaryOperation_Command.h"

/**
 * @class Add_Command
 * 
 * A class for adding two numbers via executing the add commmand
 */
class Add_Command : public BinaryOperation_Command {

    public:

    /// Default Constructor
    Add_Command (void);

    /// Destructor
    virtual ~Add_Command (void);

    /// Evaluate function to add two numbers together
	virtual int evaluate (int n1, int n2);

    /// Precendence of a number
    virtual int precedence ();
};


#endif