//
//  comp.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "comp.hpp"


/*
 * Name: Comp constructor
 * Purpose: initializes class values
 */
Comp::Comp()
{
    Comp::op1 = Op();
    Comp::op2 = Op();
    Comp::cop = CompOp();
} /* function Comp constructor */


/*
 * Name: parse
 * Purpose: parse the Comp object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Comp::parse(Tokenizer &t)
{
    /* Remove the '('  */
    TokenPair p = t.getToken();
    if(p.value != LP)
    {
        printf("Expected '('.\n");
        return ERROR;
    }
    
    /* Parse operators and comparison operator */
    if (Comp::op1.parse(&t) != SUCCESS)
        return ERROR;
    if (Comp::cop.parse(&t) != SUCCESS)
        return ERROR;
    if (Comp::op2.parse(&t) != SUCCESS)
        return ERROR;
    
    /* Remove the ')'  */
    p = t.getToken();
    if(p.value != RP)
    {
        printf("Expected ')'.\n");
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Comp object
 * Return: SUCCESS or ERROR
 */
int Comp::execute()
{
    int compOp = Comp::cop.execute();
    
    /* Evaluate each operator and return true or false based on the comparison */
    switch (compOp) {
        case 0:
            if (Comp::op1.execute() != Comp::op2.execute())
                return true;
        case 1:
            if (Comp::op1.execute() == Comp::op2.execute())
                return true;
        case 2:
            if (Comp::op1.execute() < Comp::op2.execute())
                return true;
        case 3:
            if (Comp::op1.execute() > Comp::op2.execute())
                return true;
        case 4:
            if (Comp::op1.execute() <= Comp::op2.execute())
                return true;
            
        default:
            if (Comp::op1.execute() >= Comp::op2.execute())
                return true;
    }
    
    /* If any of the above failed, return false */
    return false;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Comp object
 * Return: SUCCESS or ERROR
 */
int Comp::print()
{
    /* Print the comparison */
    printf("(");
    if (Comp::op1.print() != SUCCESS)
        return ERROR;
    printf(" ");
    if (Comp::cop.print() != SUCCESS)
        return ERROR;
    printf(" ");
    if (Comp::op2.print() != SUCCESS)
        return ERROR;
    printf(")");
    
    return SUCCESS;
} /* function print */

