//
//  table.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/21/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "table.hpp"


/*
 * Name: inTable
 * Purpose: check if the identifier has been declared
 * Parameters: string key               identifier to search for
 * Return: ERROR if not in table, index location if it is
 */
int IdTable::inTable(std::string key)
{
    if (!count)
        return ERROR;
    
    int index = 0;
    TableElement te;
    while (index < count)
    {
        te = internalIdTable.at(index);
        if (te.idName.compare(key) == 0)
            return index;
        index++;
    }
    
    return ERROR;
} /* function inTable */

//TODO: comment this
int IdTable::printTable()
{
    printf("table size: %i\n", count);
    for (int i = 0; i < count; i++)
        printf("Index %i: key %s value: %i initialized: %s\n", i, internalIdTable.at(i).idName.c_str(), \
               internalIdTable.at(i).idVal, internalIdTable.at(i).isInit ? "true" : "false");
    
    return SUCCESS;
}


 int IdTable::setElement(int index, TableElement element)
{
    if (index < count)
    {
        TableElement te = internalIdTable[index];
        te.idVal = element.idVal;
        te.isInit = element.isInit;
        internalIdTable[index] = te;
    }
    else
    {
        printf("Invalid index location.\n");
        return ERROR;
    }

    return SUCCESS;
}



TableElement IdTable::getElement(int index)
{
    if (index < count)
        return internalIdTable.at(index);
    return { "", ERROR, false };
}

void IdTable::addElement(TableElement element)
{
    count++;
    internalIdTable.push_back(element);
}


