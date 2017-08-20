//
//  compop.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "compop.hpp"


/*
 * Name: CompOp constructor
 * Purpose: initializes class values
 */
CompOp::CompOp()
{
    CompOp::option = 0;
} /* function CompOp constructor */


/*
 * Name: parse
 * Purpose: parse the CompOp object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int CompOp::parse(Tokenizer &t)
{
    /* Remove comparison operator token */
    TokenPair p = t.getToken();
    switch (p.value) {
        case NOTEQ:
            /* Option 0 by default */
            break;
        case ISEQ:
            CompOp::option = 1;
            break;
        case LT:
            CompOp::option = 2;
            break;
        case GT:
            CompOp::option = 3;
            break;
        case LTEQ:
            CompOp::option = 4;
            break;
        case GTEQ:
            CompOp::option = 5;
            break;
            
        default:
            printf("Invalid comparison operator.\n");
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
    return CompOp::option;
} /* function execute */


/*
 * Name: print
 * Purpose: print the CompOp object
 * Return: SUCCESS or ERROR
 */
int CompOp::print()
{
    /* Print the comparison operator */
    switch (CompOp::option)
    {
        case 0:
            printf("!=");
            break;
        case 1:
            printf("==");
            break;
        case 2:
            printf("<");
            break;
        case 3:
            printf(">");
            break;
        case 4:
            printf("<=");
            break;
        case 5:
            printf(">=");
            break;
            
        default:
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

