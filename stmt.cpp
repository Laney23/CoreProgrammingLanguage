//
//  stmt.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "stmt.hpp"


/*
 * Name: Stmt constructor
 * Purpose: initializes class values
 */
Stmt::Stmt()
{
    /* Initialize variables */
    option = 0;
}; /* function Stmt constructor */


/*
 * Name: parse
 * Purpose: parse the Stmt object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Stmt::parse(Tokenizer t)
{
    /* Check the first token */
    TokenPair p = t.front();
    
    /* Parse each type of statement individually */
    switch (p.value) {
        case 5:        /* if */
            Stmt::iff = If();
            if (Stmt::iff.parse(t) != SUCCESS)
                return ERROR;
            break;
        case 8:       /* while */
            Stmt::option = 1;
            Stmt::loop = Loop();
            if (Stmt::loop.parse() != SUCCESS)
                return ERROR;
            break;
        case 10:     /* read */
            Stmt::option = 2;
            Stmt::in = Input();
            if (Stmt::in.parse() != SUCCESS)
                return ERROR;
            break;
        case 11:     /* write */
            Stmt::option = 3;
            Stmt::out = Output();
            if (Stmt::out.parse() != SUCCESS)
                return ERROR;
            break;
        case 32:     /* identifier */
            Stmt::option = 4;
            Stmt::assign = Assign();
            if (Stmt::assign.parse() != SUCCESS)
                return ERROR;
            break;
            
        default:
            break;      /* Should never happen */
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Stmt object
 * Return: SUCCESS or ERROR
 */
int Stmt::execute()
{
    /* Execute the proper statement */
    switch (Stmt::option) {
        case 0:
            if (Stmt::iff.execute() != SUCCESS)
                return ERROR;
            break;
        case 1:
            if (Stmt::loop.execute() != SUCCESS)
                return ERROR;
            break;
        case 2:
            if (Stmt::in.execute() != SUCCESS)
                return ERROR;
            break;
        case 3:
            if (Stmt::out.execute() != SUCCESS)
                return ERROR;
            break;
        case 4:
            if (Stmt::assign.execute() != SUCCESS)
                return ERROR;
            break;
            
        default:            /* This will never happen */
            break;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Stmt object
 * Return: SUCCESS or ERROR
 */
int Stmt::print()
{

    // TODO
    // also include newline at the end
    return SUCCESS;
} /* function print */



