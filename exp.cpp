//
//  exp.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "exp.hpp"


//TODO: comment this
Exp::~Exp()
{
    delete fact;
    delete exp;
}


/*
 * Name: parse
 * Purpose: parse the Exp object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Exp::parse(Tokenizer *t)
{
    /* Parse the factor */
    fact = new Fact;
    if (fact->parse(t) != SUCCESS)
        return ERROR;
    
    /* Check if it's + or -  */
    TokenPair p = t->front();
    if(p.value == PLUS)
    {
        option = 1;
        /* Remove '+' */
        t->getToken();
        exp = new Exp;
        if (exp->parse(t) != SUCCESS)
            return ERROR;
    }
    else if (p.value == MINUS)
    {
        option = 2;
        /* Remove '-' */
        t->getToken();
        exp = new Exp;
        if (exp->parse(t) != SUCCESS)
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
    switch (option) {
        case 0:
            return fact->execute();
        case 1:
            return fact->execute() + exp->execute();
        case 2:
            return fact->execute() - exp->execute();
            
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
    if (fact->print() != SUCCESS)
        return ERROR;
    
    /* Add +/- if necessary */
    if (option == 0)
        return SUCCESS;
    else if (option == 1)
        printf(" + ");
    else
        printf(" - ");
    
    if (exp->print() != SUCCESS)
        return ERROR;
    
    return SUCCESS;
} /* function print */

