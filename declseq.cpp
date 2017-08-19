//
//  declseq.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "declseq.hpp"


/*
 * Name: DeclSeq constructor
 * Purpose: initializes class values
 * Parameters:  Tokenizer toke                 tokenizer object to parse
 */
DeclSeq::DeclSeq(Tokenizer toke)
{
    /* Initialize variables */
    DeclSeq::decl = Decl(toke);
    option = 0;
}; /* function DeclSeq constructor */


/*
 * Name: parse
 * Purpose: parse the DeclSeq object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int parse(Tokenizer t)
{
    /* Verify the first token */
    TokenPair p = t.front();
    if (p.token.compare("int") != 0)
    {
        printf("int keyword expected.\n");
        return ERROR;
    }
    
    /* Parse declaration */
    DeclSeq::decl.parse(t);
    
    /* If the next token is 'int', then this is a sequence. Create the DeclSeq child and parse it */
    p = t.front();
    if (p.token.compare("int") == 0)
    {
        DeclSeq::option = 1;
        DeclSeq::declSeq = DeclSeq(t);
        DeclSeq::declSeq.parse(t);
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the DeclSeq object
 * Return: SUCCESS or ERROR
 */
int execute()
{
    /* Execute the declaration */
    if (Program::decl.execute() != SUCCESS)
        return ERROR;
    
    /* Execute the declaration sequence */
    if (DeclSeq::option == 1)
    {
        if (DeclSeq::declSeq.execute() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the DeclSeq object
 * Return: SUCCESS or ERROR
 */
int print()
{
    /* Print the declaration  */
    if (Program::decl.print() != SUCCESS)
        return ERROR;
    
    /* Print the declaration sequence */
    if (DeclSeq::option == 1)
    {
        if (DeclSeq::declSeq.print() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

