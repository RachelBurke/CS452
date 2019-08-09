// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke
#ifndef _MODULAR_COMMAND_H_
#define _MODULAR_COMMAND_H_

#include "BinaryOperation_Command.h"
#include <exception>

/**
 * @class Modular_Command
 * 
 * A class for moding two numbers via executing the Modular commmand
 */
class Modular_Command : public BinaryOperation_Command {

    public:

    /// Default Constructor
    Modular_Command (void);

    /// Destructor
    ~Modular_Command (void);

    /// Evaluate function to compute the modular operation between two numbers together
	virtual int evaluate (int n1, int n2);

    /// Precendence of a number
    virtual int precedence ();

    /// Exception class for modular-by-zero incident.
    class Modular_By_Zero : public std::exception {
    public:
        /// Default constructor.
        Modular_By_Zero(void): std::exception() { }
    };
};


#endif