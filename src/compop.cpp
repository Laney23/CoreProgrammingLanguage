//
//  compop.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/compop.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the CompOp object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int CompOp::parse(Tokenizer *t)
{
    /* Remove comparison operator token */
    TokenPair p = t->getToken();
    
    switch (p.value) {
        case NOTEQ:
            /* Option 0 by default */
            break;
        case ISEQ:
            option = 1;
            break;
        case LT:
            option = 2;
            break;
        case GT:
            option = 3;
            break;
        case LTEQ:
            option = 4;
            break;
        case GTEQ:
            option = 5;
            break;
            
        default:
            cout << "Invalid comparison operator.\n";
            return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the CompOp object
 * Return: The option value for which comparison is being done 
 */
int CompOp::execute()
{
    return option;
} /* function execute */


/*
 * Name: print
 * Purpose: print the CompOp object
 * Return: SUCCESS or ERROR
 */
int CompOp::print()
{
    /* Print the comparison operator */
    switch (option)
    {
        case 0:
            cout << "!=";
            break;
        case 1:
            cout << "==";
            break;
        case 2:
            cout << "<";
            break;
        case 3:
            cout << ">";
            break;
        case 4:
            cout << "<=";
            break;
        case 5:
            cout << ">=";
            break;
            
        default:
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

