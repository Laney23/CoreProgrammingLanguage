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
 * Parameters:  Tokenizer toke                 tokenizer object to parse
 */
Program::Program(Tokenizer toke)
{
    /* Initialize variables */
    Program::ds = DeclSeq(toke);
    Program::ss = StmtSeq(toke);
} /* function Program constructor */


/*
 * Name: parse
 * Purpose: parse the Program object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int parse(Tokenizer t)
{
    /* Initialize variables */
    TokenPair p = t.getToken();
    
    /* Remove "program" */
    std::transform(p.token.begin(), p.token.end(), p.token.begin(), ::tolower);
    if(p.token.compare("program") != 0)
    {
        printf("Expected reserved word: program");
        return ERROR;
    }
    
    /* Parse declaration sequence */
    Program::ds.parse(t);
    
    /* Remove "begin" */
    p = t.getToken();
    std::transform(p.token.begin(), p.token.end(), p.token.begin(), ::tolower);
    if(p.token.compare("begin") != 0)
    {
        printf("Expected reserved word: begin");
        return ERROR;
    }
    
    /* Parse statement sequence */
    Program::ss.parse(t);
    
    /* Remove "end" */
    p = t.getToken();
    std::transform(p.token.begin(), p.token.end(), p.token.begin(), ::tolower);
    if(p.token.compare("end") != 0)
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
int execute()
{
    /* Execute the declaration sequence */
    if (Program::ds.execute() != SUCCESS)
        return ERROR;
    
    /*
     # Change idTable to Statement Sequence from Declaration Sequence
     # (No more variables can be declared after this point)
     for i in xrange(0,len(idTable)):
     idTable[i] = idTable[i][:2] + (False, False)
     */
    
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
int print()
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


