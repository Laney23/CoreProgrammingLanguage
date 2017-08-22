//
//  fact.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "fact.hpp"

using namespace std;


/*
 * Name: Fact destructor
 * Purpose: destroy the Fact object
 */
Fact::~Fact()
{
    delete op;
    if(option == 1)
        delete f;
} /* function Fact destructor */


/*
 * Name: parse
 * Purpose: parse the Fact object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Fact::parse(Tokenizer *t)
{
    /* Parse the operator */
    op = new Op;
    if (op->parse(t) != SUCCESS)
        return ERROR;
    
    /* Check if it's + or -  */
    TokenPair p = t->front();
    if(p.value == TIMES)
    {
        option = 1;
        /* Remove '*' */
        t->getToken();
        
        /* Parse factor */
        f = new Fact;
        if (f->parse(t) != SUCCESS)
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
    /* Execute the operators. Multiply them if necessary */
    if (option == 1)
        return op->execute() * f->execute();
    else
        return op->execute();
 } /* function execute */


/*
 * Name: print
 * Purpose: print the Fact object
 * Return: SUCCESS or ERROR
 */
int Fact::print()
{
    /* Print the factor */
    if (op->print() != SUCCESS)
        return ERROR;
    
    /* Add * if necessary */
    if (option == 1)
    {
        cout << " * ";
        if (f->print() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

