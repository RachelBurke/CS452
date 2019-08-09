// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke
#ifndef _BINARYOPERATION_COMMAND_H_
#define _BINARYOPERATION_COMMAND_H_

#include "Command.h"

/**
 * @class BinaryOperation_Command
 * 
 *  A template class for the binary operations +, -, *, /, %
 */
class BinaryOperation_Command: public Command
{
    public:

    /// Default Constructor
	BinaryOperation_Command (void);
    
    /// Deconstructor
	virtual ~BinaryOperation_Command (void);

    /// Method to execute an operation
    virtual bool execute (std::stack<int> &s);

    /// Method to be implemented in the respective command classes
    /// Which will be to execute the respective operation
	virtual int evaluate (int n1, int n2) = 0;

    //Method to be implemented by the respective commands
    virtual int precedence () = 0;
      
};


#endif