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
 * Return: -1 if not in table, index location if it is
 */
int IdTable::inTable(std::string key)
{
    if (!count)
        return -1;
    
    int index = 0;
    TableElement te;
    while (index < count)
    {
        te = internalIdTable.at(index++);
printf("key: %s\ttable: %s\n", key.c_str(), te.idName.c_str());
        if (te.idName.compare(key) == 0)
            return --index;
    }
    
    return -1;
} /* function inTable */

//TODO: comment this
int IdTable::printTable()
{
    printf("table size: %i\n", count);
    for (int i = 0; i < count; i++)
        printf("\n%i: %s\n", i, internalIdTable.at(i).idName.c_str());
    
    return SUCCESS;
}


 int IdTable::setElement(int index, TableElement element)
{
    if (index < count)
        internalIdTable.at(index) = element;
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


