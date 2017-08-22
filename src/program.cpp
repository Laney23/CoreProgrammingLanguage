/*
*  program.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/19/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include "program.hpp"
using namespace std;


/*
 * Name: parse
 * Purpose: parse the Program object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Program::parse(Tokenizer *t)
{
    /* Initialize variables */
    TokenPair p = t->getToken();
    
    /* Remove "program" */
    if(p.value != PROGRAM)
    {
        cout << "Expected reserved word: program.\n";
        return ERROR;
    }
    
    /* Parse declaration sequence */
    ds = new DeclSeq;
    if (ds->parse(t) != SUCCESS)
        return ERROR;

    /* Remove "begin" */
    p = t->getToken();
    if(p.value != BEGIN)
    {
        cout << "Expected reserved word: begin.\n";
        return ERROR;
    }

    /* Parse statement sequence */
    ss = new StmtSeq;
    if (ss->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove "end" */
    p = t->getToken();
    if(p.value != END)
    {
        cout << "Expected reserved word: end";
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Program object
 * Return: SUCCESS or ERROR
 */
int Program::execute()
{
    cout << "===================\nExecution Output\n";
    /* Execute the declaration sequence */
    if (ds->execute() != SUCCESS)
        return ERROR;

    /* Change idTable to Statement Sequence from Declaration Sequence */
     inDecSeq = false;
    
    /* Execute the statement sequence */
    if (ss->execute() != SUCCESS)
        return ERROR;

    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Program object
 * Return: SUCCESS or ERROR
 */
int Program::print()
{
    cout << "program\n";
    
    /* Print the declaration sequence */
    if (ds->print() != SUCCESS)
        return ERROR;
    
    cout << "begin\n";
    
    /* Print the statement sequence */
    if (ss->print() != SUCCESS)
        return ERROR;
    
    cout << "end\n";

    return SUCCESS;
} /* function print */


