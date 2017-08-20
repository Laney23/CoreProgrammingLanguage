//
//  assign.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "assign.hpp"


/*
 * Name: parse
 * Purpose: parse the Assign object
 * Return: SUCCESS or ERROR
 */
int Assign::parse(Tokenizer *t)
{
printf("start of assign %d\n", t->front().value);
    /* Parse the identifier */
    if (id->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove '=' */
    TokenPair p = t->getToken();
    if(p.value != EQUAL)
    {
        printf("Expected '=' \n");
        return ERROR;
    }
    
    /* Parse the expression */
    if (e->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        printf("Expected ';' \n");
        return ERROR;
    }
    
printf("end of assign %d\n", t->front().value);
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Assign object
 * Return: SUCCESS or ERROR
 */
int Assign::execute()
{
    /* Check if the identifier is already in the table and then update its value if it is */
    std::string name = id->getName();
    if (ParseObject::inTable(name) >= 0)
    {
        if (id->setId(e->execute()) != SUCCESS)
            return ERROR;
    }
    else
    {
        printf("Identifier must be declared in declaration sequence.\n");
        return ERROR;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Assign object
 * Return: SUCCESS or ERROR
 */
int Assign::print()
{
    /* Print the identifier */
    std::string str = std::string("\t", ++ParseObject::indent);
    str += id->getName();
    str += " = ";
    printf("%s", str.c_str());
    
    /* Print the expression */
    if (e->print() != SUCCESS)
        return ERROR;
    
    /* Print ';' */
    printf(";\n");
    ParseObject::indent--;
    
    return SUCCESS;
} /* function print */

