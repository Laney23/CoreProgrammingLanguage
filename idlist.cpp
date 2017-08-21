//
//  idlist.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "idlist.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the IdList object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int IdList::parse(Tokenizer *t)
{
    /* Parse id */
    if (id->parse(t) != SUCCESS)
        return ERROR;
    
    /* If list of ids, continue parsing */
    TokenPair p = t->front();
    if (p.value == COMMA)
    {
        /* remove ',' */
        t->getToken();
        option = 1;
        iList = new IdList;
        if (iList->parse(t) != SUCCESS)
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
    /* Execute the id */
    if (id->execute() != SUCCESS)
        return ERROR;
    
    /* Execute the id list if necessary */
    if (option == 1)
    {
        if (iList->execute() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Id object
 * Return: SUCCESS or ERROR
 */
int IdList::print()
{
    /* Print the id */
    if (id->print() != SUCCESS) {
        return ERROR;
    }
    
    if (option == 1)
    {
        cout << ", ";
        if (iList->print() != SUCCESS) {
            return ERROR;
        }
    }
    return SUCCESS;
} /* function print */


/*
 * Name: getIdNames
 * Purpose: print the IdList object
 * Return: SUCCESS or ERROR
 */
std::string IdList::getIdNames()
{
    ostringstream os;
    os << id->getName();
    if (option)
        os << ", " << iList->getIdNames();
    
    return os.str();
} /* function getIdNames */


/*
 * Name: setId
 * Purpose: passes a value to update variables. This function can only be used
 *                after declaration sequence.
 * Return: SUCCESS or ERROR
 */
int IdList::setId(int value)
{
    if (id->setId(value) != SUCCESS)
        return ERROR;
    
    if (option == 1)
    {
        if (iList->setId(value) != SUCCESS)
            return ERROR;
    }

    return SUCCESS;
} /* function setId */

