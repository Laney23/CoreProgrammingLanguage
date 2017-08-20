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
int Cond::parse(Tokenizer &t)
{
    /* Parse based on the first token  */
    TokenPair p = t.front();
    if(p.value == LP)
    {
        Cond::comp = Comp();
        Cond::comp.parse(&t);
    }
    else if (p.value == EXCL)
    {
        Cond::option = 1;
        /* Remove '!' */
        t.getToken();
        
        /* Parse condition */
        Cond::c1 = Cond();
        Cond::c1.parse(&t);
    }
    else if (p.value == LB)
    {
        /* Remove '[' */
        t.getToken();
        
        /* Parse condition */
        Cond::c1 = Cond();
        Cond::c1.parse(&t);
        
        /* Check next token */
        p = t.front();
        if (p.value == AND)
        {
            Cond::option = 2;
            
            /* Remove '&&' */
            t.getToken();
            
            /* Parse the second condition */
            Cond::c2 = Cond();
            Cond::c2.parse(&t);
        }
        else if (p.value == OR)
        {
            Cond::option = 3;
            
            /* Remove '||' */
            t.getToken();
            
            /* Parse the second condition */
            Cond::c2 = Cond();
            Cond::c2.parse(&t);
        }
        else
        {
            printf("Invalid condition operator.\n");
            return ERROR;
        }
        
        /* Remove ']' */
        p = t.getToken();
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
    switch (Cond::option) {
        case 0:
            return Cond::comp.execute();
        case 1:
            return Cond::c1.execute();
        case 2:
            return (Cond::c1.execute() && Cond::c2.execute());
            
        default:
            return (Cond::c1.execute() || Cond::c2.execute());
    }
} /* function execute */


/*
 * Name: print
 * Purpose: print the Cond object
 * Return: SUCCESS or ERROR
 */
int Cond::print()
{
    switch (Cond::option)
    {
        case 0:
            return Cond::comp.print();
        case 1:
            printf("!");
            return Cond::c1.print();
            
        default:
            printf("[");
            if (Cond::c1.print() != SUCCESS)
                return ERROR;
            
            if (Cond::option == 2)
                printf(" && ");
            else
                printf(" || ");
            
            if (Cond::c2.print() != SUCCESS)
                return ERROR;
            printf("]");
    }

    return SUCCESS;
} /* function print */

