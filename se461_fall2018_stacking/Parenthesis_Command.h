// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke
#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Command.h"

/**
 * @class Parenthesis_Command
 * 
 * A class for Dividing two numbers via executing the divide commmand
 */
class Parenthesis_Command : public Command {

    public:

    /// Default Constructor
    Parenthesis_Command (void);

    /// Destructor
    virtual ~Parenthesis_Command (void);

    /// Execute function for the parenthesis
	virtual bool execute (std::stack<int> &s);

    /// Precendence of a number
    virtual int precedence ();
};


#endif