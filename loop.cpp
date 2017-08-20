//
//  loop.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "loop.hpp"

//TODO: comments
Loop::~Loop()
{
    delete c;
    delete ss;
}



/*
 * Name: parse
 * Purpose: parse the Loop object
 * Return: SUCCESS or ERROR
 */
int Loop::parse(Tokenizer *t)
{
    /* Remove 'while' */
    TokenPair p = t->getToken();
    if(p.value != WHILE)
    {
        printf("Expected while keyword\n");
        return ERROR;
    }
    
    /* Parse the condition */
    c = new Cond;
    if (c->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove 'loop' */
    p = t->getToken();
    if(p.value != LOOP)
    {
        printf("Expected loop keyword\n");
        return ERROR;
    }
    
    /* Parse the statement sequence */
    ss = new StmtSeq;
    if (ss->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove 'end' */
    p = t->getToken();
    if(p.value != END)
    {
        printf("Expected end keyword\n");
        return ERROR;
    }
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        printf("Missing ;\n");
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Loop object
 * Return: SUCCESS or ERROR
 */
int Loop::execute()
{
    while (c->execute())
        ss->execute();
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Loop object
 * Return: SUCCESS or ERROR
 */
int Loop::print()
{
    /* Print 'while' with correct indentation */
    std::string str = std::string("\t", ++indent);
    
    str += "while ";
    printf("%s", str.c_str());
    
    /* Print the condition */
    if (c->print() != SUCCESS)
        return ERROR;
    
    /* Print 'loop' */
    printf(" loop\n");
    
    /* Print the statement sequence */
    if (ss->print() != SUCCESS)
        return ERROR;
    
    /* Print 'while' with correct indentation */
    str = std::string("\t", indent--);
    str += "end;\n";
    
    return SUCCESS;
} /* function print */

