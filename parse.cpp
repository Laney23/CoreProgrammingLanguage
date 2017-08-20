//
//  parse.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "parse.hpp"


/*
 * Name: inTable
 * Purpose: check if the identifier has been declared
 * Parameters: string key               identifier to search for
 * Return: -1 if not in table, index location if it is
 */
int ParseObject::inTable(std::string key)
{
    if (ParseObject::idTable.size() == 0)
        return -1;
    
    int index = 0;
    TableElement te;
    while (index < ParseObject::idTable.size())
    {
        te = ParseObject::idTable.at(index++);
        if (te.idName.compare(key) == 0)
            return index;
    }
    
    return -1;
} /* function inTable */


