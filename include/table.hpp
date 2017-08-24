//
//  table.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/21/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef table_hpp
#define table_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include "../include/base.hpp"


struct TableElement {
    std::string idName;
    int idVal;
    bool isInit;
};


class IdTable
{
    std::vector<TableElement> internalIdTable;
    static IdTable *table_instance;
    int count;
    IdTable() { internalIdTable.reserve(100); count = 0; }
    
public:
    ~IdTable() { if (table_instance) delete table_instance; }
    static IdTable *instance()
    {
        if (!table_instance)
            table_instance = new IdTable;
        return table_instance;
    }
    TableElement getElement(int index);
    int setElement(int index, TableElement element);
    void addElement(TableElement element);
    int tableSize() { return count; }
    int printTable();
    int inTable(std::string key);
};


#endif /* table_hpp */
