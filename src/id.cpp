//
//  id.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/id.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the IdList object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Id::parse(Tokenizer *t)
{
    /* Remove identifier token */
    TokenPair p = t->getToken();
    if (p.value != IDENTIFIER)
    {
        cout << "Identifier expected. Token received: " << p.token << endl;
        return ERROR;
    }
    
    /* Update Identifier name */
    name = p.token;

    /* Find value in lookup table if out of declaration sequence */
    if (!inDecSeq)
        index = idTable->inTable(name);
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the IdList object
 * Return: SUCCESS
 */
int Id::execute()
{
    /*
     Nothing is done when an Identifier is executed
     */
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Id object
 * Return: SUCCESS or ERROR
 */
int Id::print()
{
    cout << name;
    
    return SUCCESS;
} /* function print */


/*
 * Name: getName
 * Purpose: gives the Id name
 * Return: SUCCESS or ERROR
 */
std::string Id::getName()
{
    return name;
} /* function getName */


/*
 * Name: setId
 * Parameters: int value            the value to update the identifier to
 * Purpose: Updates a variable's value.
 * Return: SUCCESS or ERROR
 */
int Id::setId(int value)
{
    /* See if table contains the id already. If so, get a copy of it */
    TableElement te;
    int index = idTable->inTable(name);
    if (index > 0)
        te = idTable->getElement(index);
    
    /* In Declaration Sequence and already in table */
    if (index > 0 && inDecSeq == true) {
        cout << "Variable " << te.idName << " has already been declared.\n";
        return ERROR;
    }
    /* In Statement Sequence and in table */
    else if (index >= 0 && inDecSeq == false)
    {
        te.idVal = value;
        te.isInit = true;
        idTable->setElement(index, te);
    }
    /* In Statement Sequence and not in table */
    else if (index < 0 && inDecSeq == false)
    {
        cout << "Variable " << te.idName << " was never declared. Declartion can only \
                    be done in Declaration Sequence.\n";
        return ERROR;
    }
    /* In Declaration Sequence and not in table */
    else
    {
        te.idName = name;
        te.idVal = value;
        te.isInit = false;
        idTable->addElement(te);
    }
    
    return SUCCESS;
} /* function setId */

