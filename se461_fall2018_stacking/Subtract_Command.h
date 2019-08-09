// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "BinaryOperation_Command.h"

/**
 * @class Subtract_Command
 * 
 * A class for subtracting two numbers via executing the subtract commmand
 */
class Subtract_Command : public BinaryOperation_Command {

    public:

    /// Initializing Constructor Constructor
    Subtract_Command (void);

    /// Destructor
    virtual ~Subtract_Command (void);

    /// Evaluate function to multiply two numbers together
	virtual int evaluate (int n1, int n2);

    /// Precendence of a number
    virtual int precedence ();
};


#endif