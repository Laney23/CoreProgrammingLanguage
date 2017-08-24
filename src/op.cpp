//
//  op.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "op.hpp"

using namespace std;


/*
 * Name: Op destructor
 * Purpose: destroy the Op object
 */
Op::~Op()
{
    if(option == 0)
        delete i;
    if(option == 1)
        delete id;
    if(option == 2)
        delete e;
} /* function Op destructor */


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
        i = new Int;
        if (i->parse(t) != SUCCESS)
            return ERROR;
    }
    else if(p.value == IDENTIFIER)
    {
        option = 1;
        
        /* Parse Identifier */
        id = new Id;
        if (id->parse(t) != SUCCESS)
            return ERROR;
    }
    else if(p.value == LP)
    {
        option = 2;
        /* Remove '(' */
        t->getToken();
        
        /* Parse factor */
        e = new Exp;
        if (e->parse(t) != SUCCESS)   //NOTE: DIfferent from Python
            return ERROR;
        
        p = t->getToken();
        if (p.value != RP) {
            cout << "Expected end parenthesis.\n";
            return ERROR;
        }
    }
    else
    {
        cout << "Invalid operator: " << t->front().token << endl;
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

        if ((rv = i->execute()) == ERROR)
            return ERROR;
        return rv;
    }
    else if (option == 1)
    {
        /* To execute an Identifier, look up its value in the idTable and return it. Check first if it was initialized */
        int index = idTable->inTable(id->getName());
        TableElement te = idTable->getElement(index);
        if (!te.isInit) {
            cout << "Variable " << te.idName << " was never initialized.\n";
            return ERROR;
        }
        
        /* Here, return the value of the identifier.  */
        return te.idVal;
    }
    else
    {
        int rv;
        if ((rv = e->execute()) == ERROR)
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
    else if (option == 1)
    {
        if (id->print() != SUCCESS)
            return ERROR;
    }
    /* Print the expression */
    else
    {
        cout << "(";
        if (e->print() != SUCCESS)
            return ERROR;
        cout << ")";
    }
    
    return SUCCESS;
} /* function print */

