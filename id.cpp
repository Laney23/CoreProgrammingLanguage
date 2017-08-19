//
//  id.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "id.hpp"


/*
 * Name: Id constructor
 * Purpose: initializes class values
 * Parameters:  Tokenizer toke                 tokenizer object to parse
 */
Id(Tokenizer &toke)
{
    /* Initialize variables */
    Id::name = toke.idName();
}; /* function IdList constructor */


/*
 * Name: parse
 * Purpose: parse the IdList object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Id::parse(Tokenizer &t)
{
    /* Parse id */
    IdList::id.parse(t);
    
    /* If list of ids, continue parsing */
    TokenPair p = t.front();
    
    if (p.token.compare(",") == 0)
    {
        t.getToken();       /* remove ',' */
        IdList::option = 1;
        IdList::iList = IdList(t);
        IdList::iList.parse(t);
    }
    
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
 * Purpose: print the IdList object
 * Return: SUCCESS or ERROR
 */
int Id::print()
{
    //TODO
    return Id::name;
} /* function print */


/*
 * Name: setId
 * Parameters: int value            the value to update the identifier to
 * Purpose: Updates a variable's value.
 */
int Id::setId(int value)
{
    TableElement te;
    int index = ParseObject::inTable(Id::name);
    if (index > 0)
        te = ParseObject::idTable.at(x);
    
    /* In Declaration Sequence and already in table */
    if (index > 0 && ParseObject::inDecSeq == true) {
        printf("Variable %s has already been declared.\n", te.idName);
        return ERROR;
    }
    /* In Statement Sequence and in table */
    else if (x >= 0 && te.inDecSeq == false)
    {
        
    }
    /* In Statement Sequence and not in table */
    else if (x < 0 && ParseObject::inDecSeq == false)
    {
        printf("Variable %s was never declared. Declartion can only \
                    be done in Declaration Sequence.\n", te.idName);
        return ERROR;
    }
    /* In Declaration Sequence and not in table */
    else
    {
        te.idName = Id::name;
        te.idVal = value;
        te.isInit = false;
        ParseObject::idTable.push_back(te);
    }
    
    return SUCCESS;
} /* function setId */

