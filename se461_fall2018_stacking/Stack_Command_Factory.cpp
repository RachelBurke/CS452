// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include "Stack_Command_Factory.h"

Stack_Command_Factory::Stack_Command_Factory (void) { }

Stack_Command_Factory::~Stack_Command_Factory (void) { }

Add_Command * Stack_Command_Factory::create_add_command (void)
{
	return new Add_Command();
}

Subtract_Command * Stack_Command_Factory::create_subtract_command (void)
{
	return new Subtract_Command();
}

Multiply_Command * Stack_Command_Factory::create_multiply_command (void)
{
	return new Multiply_Command();
}

Divide_Command * Stack_Command_Factory::create_divide_command (void)
{
	return new Divide_Command();
}

Modular_Command * Stack_Command_Factory::create_modular_command (void)
{
	return new Modular_Command();
}

Number_Command * Stack_Command_Factory::create_number_command (int num)
{
	return new Number_Command(num);
}

Parenthesis_Command * Stack_Command_Factory::create_parenthesis_command (void)
{
	return new Parenthesis_Command();
}
