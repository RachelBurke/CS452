// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// rburke

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stack>
#include <array>
#include "Command.h"
#include "Stack_Command_Factory.h"

//Comment: There was no segfault to worry about

int infix_to_postfix(const std::string & infix, std::array<Command *, 100> & postfix);

void evaluate_postfix(std::array<Command *, 100> & postfix, int postSize);

//
// main
//
int main (int argc, char * argv [])
{
// String Input
	std::string inputStr;
	
	bool quit = false;
	
	while (!quit)
	{
        // Ask for a math expression
		printf("\nEnter in a mathematical expression to evaluate.\n"  
                "Be sure to put spaces in between each element of the expression.\n"
                "Type \"QUIT\" to quit the program.\n"
                "Expression: ");	
		// Retrieve the input from the console by line.
		getline(std::cin, inputStr);
		
		if (inputStr.compare("QUIT") == 0)
			quit = true;
		else {
            std::array<Command *, 100> postfix;
            int postSize = 0;                                                                   //My way of making sure I do not look at NULL
            if((postSize = infix_to_postfix(inputStr, postfix)) != 0)                           //vals - just return how many things you put in
                evaluate_postfix(postfix, postSize);
		}
	}

	std::cout << "Goodbye!" << std::endl;

    return 0;
}

int infix_to_postfix (const std::string & infix, std::array <Command *, 100> & postfix) {
    std::istringstream input(infix); // create a input stream parser
    std::string token = ""; // current token in string/stream
    
    Stack_Command_Factory factory; // created factory
    Command * cmd = NULL; // created command object
    
    std::stack <Command *> temp;    //Temp stack of operations
    int i = 0;                      //use to keep track of the REAL size of postfix array

    //Comment: My taking care of Parenthesis checking
    int left = 0;;
    int right = 0;
    int left_found = 0;
    int right_found = 0;
    
    while (!input.eof())
    {
        //Read in a token
        input >> token;

        if (token == "+")
        {
            cmd = factory.create_add_command();
            while (!temp.empty() && temp.top()->precedence() >= cmd->precedence())
            {
                postfix[i++] = temp.top();
                temp.pop();
            }
            temp.push(cmd);
        }
        else if (token == "-")
        {
            cmd = factory.create_subtract_command();
            while (!temp.empty() && temp.top()->precedence() >= cmd->precedence())
            {
                postfix[i++] = temp.top();
                temp.pop();
            }
            temp.push(cmd);
        }
        else if (token == "*")
        {
            cmd = factory.create_multiply_command();
            while (!temp.empty() && temp.top()->precedence() >= cmd->precedence())
            {
                postfix[i++] = temp.top();
                temp.pop();
            }
            temp.push(cmd);
        }
        else if (token == "/")
        {
            cmd = factory.create_divide_command();
            while (!temp.empty() && temp.top()->precedence() >= cmd->precedence())
            {
                postfix[i++] = temp.top();
                temp.pop();
            }
            temp.push(cmd);
        }
        else if (token == "%")
        {
            cmd = factory.create_modular_command();
            while (!temp.empty() && temp.top()->precedence() >= cmd->precedence())
            {
                postfix[i++] = temp.top();
                temp.pop();
            }
            temp.push(cmd);
        }
        else if (token == "(")
        {
            cmd = factory.create_parenthesis_command();
            temp.push(cmd);
            left++;
        }
        else if (token == ")")
        {
            right++;
            right_found++;
            while(temp.top()->precedence() != 0)
            {
                postfix[i++] = temp.top();
                temp.pop();
            }
            //Pop the left if it exists
            if(!temp.empty())
            {
                left_found++;    
                temp.pop();          
            }
            //Not enough parentheses
            if(left_found != right_found)
            {
                while(!temp.empty())
                    temp.pop();
                for(int x = 0; x < i; i++)
                    delete postfix[i];
                std::cout << "error (invalid parentheses)" << std::endl;
                return 0;
            }
        }
        else if(!(atoi(token.c_str()) == 0 && token[0]!='0'))
        {
            int num;
            std::istringstream token_num(token);
            token_num >> num; 
            postfix[i++] = factory.create_number_command(num);
        }
        else
        {
            while(!temp.empty())
                    temp.pop();
            for(int x = 0; x < i; x++)
                delete postfix[i];
            std::cout << "error (invalid input)" << std::endl; 
            return 0;  
        }
    }
    //Done reading in - check work and take care of rest of temp
    //Not enough parentheses
    if(left != right)
    {
        while(!temp.empty())
            temp.pop();
        for(int x = 0; x < i; x++)
            delete postfix[x];
        std::cout << "error (invalid parentheses)" << std::endl;
        return 0;
    }

    //empy the temp
    while (!temp.empty())
    {
        postfix[i++] = temp.top();
        temp.pop();
    }

    delete cmd;

    return i;
}


void evaluate_postfix(std::array<Command *, 100> & postfix, int postSize)
{
    std::stack<int> s;
    int result;
    
    try
    {
        for(int i = 0; i < postSize; i++)
        {
            if(!(postfix[i]->execute(s))){
                for (int j = 0; j < postSize; j++)
                    delete postfix[j];
                std::cout << "Bad Expression" << std::endl;
                return;
            }
            delete postfix[i];
        }
    }
    catch (const Divide_Command::Divide_By_Zero & e)
    {
        std::cout << "error (divide by zero)" << std::endl;
    }
    catch (const Modular_Command::Modular_By_Zero & e)
    {
        std::cout << "error (moduland is zero)" << std::endl;
    }

    if(s.size() != 1)
    {
        while(!s.empty())
            s.pop();
        std::cout << "Bad Expression" << std::endl;
        return;
    }           
    
	result = s.top();
	s.pop();
    
    std::cout << "Result: " << result << std::endl;
    return;
}
