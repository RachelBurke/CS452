// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"

/**
 * @class Number_Command
 * 
 * A class for handling number commands
 */
class Number_Command : public Command {
	
    public:

    /// Default Constructor
    Number_Command (void);

    /// Initializing Constructor
    Number_Command (int n);

    /// Deconstructor
    ~Number_Command (void);

    /// Execute function to complete the number command
    /// which pushes the number onto the stack
	virtual bool execute (std::stack<int> &s);

    /// Precendence of a number
    virtual int precedence ();
    
    private:
    
    int n_;
};

#endif