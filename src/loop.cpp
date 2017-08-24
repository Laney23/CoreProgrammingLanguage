//
//  loop.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/loop.hpp"

using namespace std;


/*
 * Name: Loop destructor
 * Purpose: destroy the Loop object
 */
Loop::~Loop()
{
    delete c;
    delete ss;
} /* function Loop destructor */


/*
 * Name: parse
 * Purpose: parse the Loop object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Loop::parse(Tokenizer *t)
{
    /* Remove 'while' */
    TokenPair p = t->getToken();
    if(p.value != WHILE)
    {
        cout << "Expected while keyword\n";
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
        cout << "Expected loop keyword\n";
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
        cout << "Expected end keyword\n";
        return ERROR;
    }
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        cout << "Missing ;\n";
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
    cout << string(indent, '\t') <<"while ";
//    printf("%*s""while ", ++indent, "\t");
    
    /* Print the condition */
    if (c->print() != SUCCESS)
        return ERROR;
    
    /* Print 'loop' */
    cout << " loop\n";
    
    /* Print the statement sequence */
    if (ss->print() != SUCCESS)
        return ERROR;
    
    /* Print 'while' with correct indentation */
//    printf("%*s""end;\n", indent--, "\t");
    cout << string(indent, '\t') << "end;\n";
    
    return SUCCESS;
} /* function print */

