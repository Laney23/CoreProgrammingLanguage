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
Id::Id(Tokenizer toke)
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
    return Id::name;
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












class Id:			# DONE
def __init__(self,t):
self.name = ""

def parse(self):
self.name = t.getValue()
t.getToken()		# Identifier token

def setId(self, val):
x = inTable(self.name, idTable)
if x >= 0 and idTable[x][2] == True:                                            # In DS and already in table
print 'Variable already declared.'
exit()
elif x >= 0 and idTable[x][2] == False:                                        # In SS and in table
idTable[x] = idTable[x][:1] + (val, False, True)
elif x < 0 and len(idTable) > 0 and idTable[0][2] == False:			# In SS and not in table
print 'Variable %s was never declared. Declaration can only be done in Declaration Sequence.' % self.name
exit()
else:                                                                                             # In DS and not in table
idTable.append((self.name, val, True, False))

def execute(self):
return self.name

def Print(self):
return self.name
