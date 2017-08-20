//
//  op.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "op.hpp"


/*
 * Name: Op constructor
 * Purpose: initializes class values
 */
Op::Op()
{
    /* Initialize variables */
    Op::option = 0;
} /* function Exp constructor */


/*
 * Name: parse
 * Purpose: parse the Op object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Op::parse(Tokenizer &t)
{
    /* Grab the first token and parse accordingly  */
    TokenPair p = t.front();
    if(p.value == NUMBER)
    {
        /* Parse integer */
        Op::i = Int();
        if (Op::i.parse(&t) != SUCCESS)
            return ERROR;
    }
    else if(p.value == IDENTIFIER)
    {
        Op::option = 1;
        /* Remove identifier */
        t.getToken();
        
        /* Parse Identifier */
        Op::id = Id();
        if (Op::id.parse(&t) != SUCCESS)
            return ERROR;
    }
    else if(p.value == LP)
    {
        Op::option = 2;
        /* Remove '(' */
        t.getToken();
        
        /* Parse factor */
        Op::e = Exp();
        if (Op::e.parse(&t) != SUCCESS)   //NOTE: DIfferent from Python
            return ERROR;
        
        p = t.getToken();
        if (p.value != RP) {
            printf("Expected end parenthesis.\n");
            return ERROR;
        }
    }
    else
    {
        printf("Invalid operator.\n");
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Op object
 * Return: The evaluated value of the factor
 */
int Op::execute()
{
    if (Op::option == 0)
    {
        int rv;
        if ((rv = Op::i.execute()) != SUCCESS)
            return ERROR;
        return rv;
    }
    else if (Op::option == 1)
    {
        /* To execute an Identifier, look up its value in the idTable and return it. Check first if it was initialized */
        int index = ParseObject::inTable(Op::id.getName());
        TableElement te = ParseObject::idTable.at(index);
        if (!te.isInit) {
            printf("Variable %s was never initialized.\n", te.idName.c_str());
            return ERROR;
        }
        
        /* Here, return the value of the identifier.  */
        return te.idVal;
    }
    else
    {
        int rv;
        if ((rv = Op::e.execute()) != SUCCESS)
            return ERROR;
        return rv;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Op object
 * Return: SUCCESS or ERROR
 */
int Op::print()
{
    /* Print the integer */
    if (Op::option == 0)
    {
        if (Op::i.print() != SUCCESS)
            return ERROR;
    }
    /* Print the identifier */
    if (Op::option == 1)
    {
        if (Op::id.print() != SUCCESS)
            return ERROR;
    }
    /* Print the expression */
    else
    {
        printf("(");
        if (Op::e.print() != SUCCESS)
            return ERROR;
        printf(")");
    }
    
    return SUCCESS;
} /* function print */

