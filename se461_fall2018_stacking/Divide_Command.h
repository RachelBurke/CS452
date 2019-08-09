// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke
#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "BinaryOperation_Command.h"
#include <exception>

/**
 * @class Divide_Command
 * 
 * A class for Dividing two numbers via executing the divide commmand
 */
class Divide_Command : public BinaryOperation_Command {

    public:

    /// Default Constructor
    Divide_Command (void);

    /// Destructor
    virtual ~Divide_Command (void);

    /// Evaluate function to divide two numbers together
	virtual int evaluate (int n1, int n2);

    /// Precendence of a number
    virtual int precedence ();

    /// Exception class for divide-by-zero incident.
    class Divide_By_Zero : public std::exception {
    public:
        /// Default constructor.
        Divide_By_Zero(void): std::exception() { }
    };
};


#endif