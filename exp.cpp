//
//  exp.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "exp.hpp"


/*
 * Name: Exp constructor
 * Purpose: initializes class values
 */
Exp::Exp()
{
    /* Initialize variables */
    Exp::fact = Fact();
    Exp::exp = Exp();
    Exp::option = 0;
} /* function Exp constructor */


/*
 * Name: parse
 * Purpose: parse the Exp object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Exp::parse(Tokenizer &t)
{
    /* Parse the factor */
    if (Exp::fact.parse(&t) != SUCCESS)
        return ERROR;
    
    /* Check if it's + or -  */
    TokenPair p = t.front();
    if(p.value == PLUS)
    {
        /* Remove '+' */
        t.getToken();
        if (Exp::exp.parse(&t) != SUCCESS)
            return ERROR;
    }
    else if (p.value == MINUS)
    {
        Exp::option = 2;
        /* Remove '-' */
        t.getToken();
        if (Exp::exp.parse(&t) != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Exp object
 * Return: The evaluated value of the expression
 */
int Exp::execute()
{
    switch (Exp::option) {
        case 0:
            return Exp::fact.execute();
        case 1:
            return Exp::fact.execute() + Exp::exp.execute();
        case 2:
            return Exp::fact.execute() - Exp::exp.execute();
            
        default:
            return ERROR;
    }
    
} /* function execute */


/*
 * Name: print
 * Purpose: print the Exp object
 * Return: SUCCESS or ERROR
 */
int Exp::print()
{
    /* Print the factor */
    if (Exp::fact.print() != SUCCESS)
        return ERROR;
    
    /* Add +/- if necessary */
    if (Exp::option == 0)
        return SUCCESS;
    else if (Exp::option == 1)
        printf(" + ");
    else
        printf(" - ");
    
    if (Exp::exp.print() != SUCCESS)
        return ERROR;
    
    return SUCCESS;
} /* function print */

