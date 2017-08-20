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
 * Name: Program constructor
 * Purpose: initializes class values
 */
Program::Program()
{
    /* Initialize variables */
    ParseObject::idTable.reserve(100);
    ParseObject::inDecSeq = true;
    ParseObject::indent = 0;
    Program::ds = DeclSeq();
    Program::ss = StmtSeq();
} /* function Program constructor */


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
        printf("Expected reserved word: program");
        return ERROR;
    }
    
    /* Parse declaration sequence */
    if (Program::ds.parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove "begin" */
    p = t->getToken();
    if(p.value != BEGIN)
    {
        printf("Expected reserved word: begin");
        return ERROR;
    }
    
    /* Parse statement sequence */
    if (Program::ss.parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove "end" */
    p = t->getToken();
    if(p.value != END)
    {
        printf("Expected reserved word: end");
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
    /* Execute the declaration sequence */
    if (Program::ds.execute() != SUCCESS)
        return ERROR;
    
    /* Change idTable to Statement Sequence from Declaration Sequence */
     ParseObject::inDecSeq = false;
    
    /* Execute the statement sequence */
    if (Program::ss.execute() != SUCCESS)
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
    printf("program\n");
    
    /* Print the declaration sequence */
    if (Program::ds.print() != SUCCESS)
        return ERROR;
    
    printf("begin\n");
    
    /* Print the statement sequence */
    if (Program::ss.print() != SUCCESS)
        return ERROR;
    
    printf("end\n");
    
    return SUCCESS;
} /* function print */


