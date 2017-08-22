//
//  assign.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "assign.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the Assign object
 * Return: SUCCESS or ERROR
 */
int Assign::parse(Tokenizer *t)
{
    /* Parse the identifier */
    if (id->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove '=' */
    TokenPair p = t->getToken();
    if(p.value != EQUAL)
    {
        cout << "Expected '=' \n";
        return ERROR;
    }
    
    /* Parse the expression */
    if (e->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        cout << "Expected ';' \n";
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Assign object
 * Return: SUCCESS or ERROR
 */
int Assign::execute()
{
    /* Check if the identifier is already in the table and then update its value if it is */
    string name = id->getName();
    if (idTable->inTable(name) >= 0)
    {
        if (id->setId(e->execute()) != SUCCESS)
            return ERROR;
    }
    else
    {
        cout << "Identifier must be declared in declaration sequence.\n";
        return ERROR;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Assign object
 * Return: SUCCESS or ERROR
 */
int Assign::print()
{
    /* Print the identifier */
    cout << string(indent, '\t') << id->getName() << " = ";
    
    /* Print the expression */
    if (e->print() != SUCCESS)
        return ERROR;
    
    /* Print ';' */
    cout << ";\n";
    
    return SUCCESS;
} /* function print */

