//
//  comp.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "comp.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the Comp object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Comp::parse(Tokenizer *t)
{
    /* Remove the '('  */
    TokenPair p = t->getToken();
    if(p.value != LP)
    {
        cout << "Expected '('.\n";
        return ERROR;
    }
    
    /* Parse operators and comparison operator */
    op1 = new Op;
    if (op1->parse(t) != SUCCESS)
        return ERROR;
    cop = new CompOp;
    if (cop->parse(t) != SUCCESS)
        return ERROR;
    op2 = new Op;
    if (op2->parse(t) != SUCCESS)
        return ERROR;

    /* Remove the ')'  */
    p = t->getToken();
    if(p.value != RP)
    {
        cout << "Expected ')'.\n";
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
    int compOp = cop->execute();
    
    /* Evaluate each operator and return true or false based on the comparison */
    switch (compOp) {
        case 0:
            if (op1->execute() != op2->execute())
                return true;
        case 1:
            if (op1->execute() == op2->execute())
                return true;
        case 2:
            if (op1->execute() < op2->execute())
                return true;
        case 3:
            if (op1->execute() > op2->execute())
                return true;
        case 4:
            if (op1->execute() <= op2->execute())
                return true;
            
        default:
            if (op1->execute() >= op2->execute())
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
    cout << "(";
    if (op1->print() != SUCCESS)
        return ERROR;
    cout << " ";
    if (cop->print() != SUCCESS)
        return ERROR;
    cout << " ";
    if (op2->print() != SUCCESS)
        return ERROR;
    cout << ")";
    
    return SUCCESS;
} /* function print */

