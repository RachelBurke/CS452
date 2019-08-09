// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#ifndef _STACK_FACTORY_H_
#define _STACK_FACTORY_H_

#include "Command_Factory.h"

/**
 * @class Stack_Expr_Command_Factory
 * 
 * This is a concrete factory class for expression commands 
 */
class Stack_Command_Factory : public Command_Factory
{
    public:
    
    Stack_Command_Factory (void);
    virtual ~Stack_Command_Factory (void);
    
    virtual Add_Command * create_add_command (void);
    virtual Subtract_Command * create_subtract_command (void);
    virtual Multiply_Command * create_multiply_command (void);
    virtual Divide_Command * create_divide_command (void);
    virtual Modular_Command * create_modular_command (void);
    virtual Number_Command * create_number_command (int num);
    virtual Parenthesis_Command * create_parenthesis_command (void);
};

#endif