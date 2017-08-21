//
//  cond.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "cond.hpp"


/*
 * Name: parse
 * Purpose: parse the Cond object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Cond::parse(Tokenizer *t)
{
    /* Parse based on the first token  */
    TokenPair p = t->front();
    if(p.value == LP)
    {
        comp = new Comp;
        if (comp->parse(t) != SUCCESS)
            return ERROR;
    }
    else if (p.value == EXCL)
    {
        option = 1;
        /* Remove '!' */
        t->getToken();
        
        /* Parse condition */
        c1 = new Cond;
        if (c1->parse(t) != SUCCESS)
            return ERROR;
    }
    else if (p.value == LB)
    {
        /* Remove '[' */
        t->getToken();
        
        /* Parse condition */
        c1 = new Cond;
        if (c1->parse(t) != SUCCESS)
            return ERROR;
        
        /* Check next token */
        p = t->front();
        if (p.value == AND || p.value == OR)
        {
            p.value == AND ? option = 2 : option = 3;
            
            /* Remove '&&' or '||' */
            t->getToken();
            
            /* Parse the second condition */
            c2 = new Cond;
            if (c2->parse(t) != SUCCESS)
                return ERROR;
        }
        else
        {
            printf("Invalid condition operator.\n");
            return ERROR;
        }
        
        /* Remove ']' */
        p = t->getToken();
        if (p.value != RB)
        {
            printf("Missing: ]");
            return ERROR;
        }
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Cond object
 * Return: SUCCESS or ERROR
 */
int Cond::execute()
{
    //TODO: Error check these
    switch (option) {
        case 0:
            return comp->execute();
        case 1:
            return c1->execute();
        case 2:
            return (c1->execute() && c2->execute());
            
        default:
            return (c1->execute() || c2->execute());
    }
} /* function execute */


/*
 * Name: print
 * Purpose: print the Cond object
 * Return: SUCCESS or ERROR
 */
int Cond::print()
{
    switch (option)
    {
        case 0:
            return comp->print();
        case 1:
            printf("!");
            return c1->print();
            
        default:
            printf("[");
            if (c1->print() != SUCCESS)
                return ERROR;
            
            if (option == 2)
                printf(" && ");
            else
                printf(" || ");
            
            if (c2->print() != SUCCESS)
                return ERROR;
            printf("]");
    }

    return SUCCESS;
} /* function print */

