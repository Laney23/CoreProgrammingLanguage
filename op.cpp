//
//  op.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "op.hpp"


//TODO: comment this
Op::~Op()
{
    if(option == 0)
        delete i;
    if(option == 1)
        delete id;
    if(option == 2)
        delete e;
}

/*
 * Name: parse
 * Purpose: parse the Op object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Op::parse(Tokenizer *t)
{
    /* Grab the first token and parse accordingly  */
    TokenPair p = t->front();
    if(p.value == NUMBER)
    {
        /* Parse integer */
        i = new Int();
        if (i->parse(t) != SUCCESS)
            return ERROR;
    }
    else if(p.value == IDENTIFIER)
    {
        option = 1;
        /* Remove identifier */
        t->getToken();
        
        /* Parse Identifier */
        id = new Id();
        if (id->parse(t) != SUCCESS)
            return ERROR;
    }
    else if(p.value == LP)
    {
        option = 2;
        /* Remove '(' */
        t->getToken();
        
        /* Parse factor */
        e = new Exp();
        if (e->parse(t) != SUCCESS)   //NOTE: DIfferent from Python
            return ERROR;
        
        p = t->getToken();
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
    if (option == 0)
    {
        int rv;
        if ((rv = i->execute()) != SUCCESS)
            return ERROR;
        return rv;
    }
    else if (option == 1)
    {
        /* To execute an Identifier, look up its value in the idTable and return it. Check first if it was initialized */
        int index = ParseObject::inTable(Op::id->getName());
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
        if ((rv = e->execute()) != SUCCESS)
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
    if (option == 0)
    {
        if (i->print() != SUCCESS)
            return ERROR;
    }
    /* Print the identifier */
    if (option == 1)
    {
        if (Op::id->print() != SUCCESS)
            return ERROR;
    }
    /* Print the expression */
    else
    {
        printf("(");
        if (e->print() != SUCCESS)
            return ERROR;
        printf(")");
    }
    
    return SUCCESS;
} /* function print */

