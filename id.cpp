//
//  id.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "id.hpp"


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
        printf("Identifier expected.\n");
        return ERROR;
    }
    
    /* Update Identifier name */
    name = p.token;
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the IdList object
 * Return: SUCCESS or ERROR
 */
int Id::execute()
{
    //TODO
    /*
     """
     Execute returns a string with the id names delimited with commas to the caller. This is a
     cheat so that IdList can be called recursively
     """
     def execute(self):
     returnString = self.id.execute()
     if self.option == 1:
     returnString += ',' + self.iList.execute()
     return returnString
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
    printf("%s", name.c_str());
    
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
        printf("Variable %s has already been declared.\n", te.idName.c_str());
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
        printf("Variable %s was never declared. Declartion can only \
                    be done in Declaration Sequence.\n", te.idName.c_str());
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

