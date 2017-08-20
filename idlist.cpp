//
//  idlist.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "idlist.hpp"


/*
 * Name: IdList constructor
 * Purpose: initializes class values
 */
IdList::IdList()
{
    /* Initialize variables */
    IdList::id = Id();
    IdList::option = 0;
}; /* function IdList constructor */


/*
 * Name: parse
 * Purpose: parse the IdList object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int IdList::parse(Tokenizer t)
{
    /* Parse id */
    if (IdList::id.parse(t) != SUCCESS)
        return ERROR;
    
    /* If list of ids, continue parsing */
    TokenPair p = t.front();
    if (p.value == COMMA)
    {
        t.getToken();       /* remove ',' */
        IdList::option = 1;
        IdList::iList = IdList();
        if (IdList::iList.parse(t) != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the IdList object
 * Return: SUCCESS or ERROR
 */
int IdList::execute()
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
std::string IdList::getIdNames()
{
    std::string returnString = IdList::id.getName();
    if (IdList::option == 1)
    {
        returnString += ", ";
        returnString += IdList::iList.print();
    }
    
    return returnString;
} /* function print */


/*
 * Name: setId
 * Purpose: passes a value to update variables. This function can only be used
 *                after declaration sequence.
 * Return: SUCCESS or ERROR
 */
int IdList::setId(int value)
{
    if (IdList::id.setId(value) != SUCCESS)
        return ERROR;
    
    if (IdList::option == 1)
    {
        if (IdList::iList.setId(value) != SUCCESS)
            return ERROR;
    }

    return SUCCESS;
} /* function setId */

