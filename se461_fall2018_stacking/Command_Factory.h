// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke
#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modular_Command.h"
#include "Number_Command.h"
#include "Parenthesis_Command.h"

/**
 * @class Expr_Command_Factory
 * 
 * This abstract factory class is a template for expression commands 
 */
class Command_Factory
{
    public:

    /// Initalizing Constructor
    Command_Factory (void) = default;

    /// Deconstructor
    virtual ~Command_Factory (void) = default;

    /// Abstract add command to be completed by the stack factory
    virtual Add_Command * create_add_command (void) = 0;

    /// Abstract subtract command to be completed by the stack factory
    virtual Subtract_Command * create_subtract_command (void) = 0;

    /// Abstract multiply command to be completed by the stack factory
    virtual Multiply_Command * create_multiply_command (void) = 0;

    /// Abstract divide command to be completed by the stack factory
    virtual Divide_Command * create_divide_command (void) = 0;

    /// Abstract modular command to be completed by the stack factory
    virtual Modular_Command * create_modular_command (void) = 0;

    /// Abstract number command to be completed by the stack factory
    virtual Number_Command * create_number_command (int n) = 0;

    /// Abstract parenthesis command to be completed by the stack factory
    virtual Parenthesis_Command * create_parenthesis_command (void) = 0;
    
    private:
    ///  prevent the following operations
    Command_Factory (const Command_Factory &);
    const Command_Factory & operator = (const Command_Factory &);
};


#endif