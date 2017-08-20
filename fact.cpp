//
//  fact.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "fact.hpp"


/*
 * Name: parse
 * Purpose: parse the Fact object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Fact::parse(Tokenizer *t)
{
    /* Parse the operator */
    if (Fact::op.parse(t) != SUCCESS)
        return ERROR;
    
    /* Check if it's + or -  */
    TokenPair p = t->front();
    if(p.value == TIMES)
    {
        Fact::option = 1;
        /* Remove '*' */
        t->getToken();
        
        /* Parse factor */
        Fact::f = Fact();
        if (Fact::f.parse(t) != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Fact object
 * Return: The evaluated value of the factor
 */
int Fact::execute()
{
    //TODO
    if (Fact::option == 1)
        return Fact::op.execute() * Fact::f.execute();
    else
        return Fact::op.execute();
 } /* function execute */


/*
 * Name: print
 * Purpose: print the Fact object
 * Return: SUCCESS or ERROR
 */
int Fact::print()
{
    /* Print the factor */
    if (Fact::op.print() != SUCCESS)
        return ERROR;
    
    /* Add * if necessary */
    if (Fact::option == 1)
    {
        printf(" * ");
        if (Fact::f.print() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

