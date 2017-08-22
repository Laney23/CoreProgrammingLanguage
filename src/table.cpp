//
//  table.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/21/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "table.hpp"

using namespace std;


/*
 * Name: inTable
 * Purpose: check if the identifier has been declared
 * Parameters: string key               identifier to search for
 * Return: ERROR if not in table, index location if it is
 */
int IdTable::inTable(string key)
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


/*
 * Name: printTable
 * Purpose: prints all the values within the table
 * Return: SUCCESS
 */
int IdTable::printTable()
{
    cout << "table size: " << count << endl;
    for (int i = 0; i < count; i++)
        cout << "Index: " << i << " key: " << internalIdTable.at(i).idName << " value: "  \
        << internalIdTable.at(i).idVal << " Initialized: " << (internalIdTable.at(i).isInit ? "true\n" : "false\n");
    
    return SUCCESS;
} /* function printTable */


/*
 * Name: setElement
 * Purpose: Updates a TableElement already in the table
 * Parameters: int index                            TableElement to be updated
 *                     TableElement element      TE containing values to update to
 * Return: SUCCESS or ERROR
 */
 int IdTable::setElement(int index, TableElement element)
{
    /* Ensure no bounds issues */
    if (index < count)
    {
        TableElement te = internalIdTable[index];
        te.idVal = element.idVal;
        te.isInit = element.isInit;
        internalIdTable[index] = te;
    }
    else
    {
        cout << "Invalid index location.\n";
        return ERROR;
    }

    return SUCCESS;
} /* function setElement */


/*
 * Name: getElement
 * Purpose: Grab a TableElement from the table
 * Parameters: int index                  TableElement to get
 * Return: the TableElement at index, or an error TableElement
 */
TableElement IdTable::getElement(int index)
{
    if (index < count)
        return internalIdTable.at(index);
    return { "", ERROR, false };
} /* function getElement */


/*
 * Name: addElement
 * Purpose: Adds a new TableElement to the table
 * Parameters: TableElement element                  TableElement to add
 */
void IdTable::addElement(TableElement element)
{
    count++;
    internalIdTable.push_back(element);
} /* function addElement */


