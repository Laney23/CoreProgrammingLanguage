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
 * Parameters:  Tokenizer toke                 tokenizer object to parse
 */
IdList::IdList(Tokenizer toke)
{
    /* Initialize variables */
    IdList::id = Id(toke);
    option = 0;
}; /* function IdList constructor */


/*
 * Name: parse
 * Purpose: parse the IdList object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int parse(Tokenizer t)
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
int execute()
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
int print()
{
    string returnString = IdList::id.print();
    if (IdList::option == 1)
    {
        //TODO
        //returnString += ", " + str(self.iList.Print())
    }
    
    return returnString;
} /* function print */


/*
 * Name: setId
 * Purpose: passes a value to update variables. This function can only be used
 *                after declaration sequence.
 */
void setId(int value)
{
    IdList::id.setId(value);
    
    if (IdList::option == 1)
        IdList::iList.setId(value);
} /* function setId */

