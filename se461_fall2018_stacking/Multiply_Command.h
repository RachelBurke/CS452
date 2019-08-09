// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "BinaryOperation_Command.h"

/**
 * @class Multiply_Command
 * 
 * A class for Multiplying two numbers via executing the multiply commmand
 */
class Multiply_Command : public BinaryOperation_Command {

    public:

    /// Default Constructor
    Multiply_Command (void);

    /// Destructor
    virtual ~Multiply_Command (void);

    /// Evaluate function to multiply two numbers together
	virtual int evaluate (int n1, int n2);

    /// Precendence of a number
    virtual int precedence ();
};

#endif