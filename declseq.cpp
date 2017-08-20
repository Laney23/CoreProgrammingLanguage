//
//  declseq.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "declseq.hpp"


/*
 * Name: parse
 * Purpose: parse the DeclSeq object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int DeclSeq::parse(Tokenizer *t)
{
    /* Verify the first token */
    TokenPair p = t->front();
    if (p.value != INT)
    {
        printf("int keyword expected. Got %d\n", p.value);
        return ERROR;
    }
    
    /* Parse declaration */
    if (DeclSeq::decl->parse(t) != SUCCESS)
        return ERROR;
    
    /* If the next token is 'int', then this is a sequence. Create the DeclSeq child and parse it */
    p = t->front();
    std::transform(p.token.begin(), p.token.end(), p.token.begin(), ::tolower);
    if (p.value == INT)
    {
        DeclSeq::option = 1;
        DeclSeq::declSeq = new DeclSeq();
        if (DeclSeq::declSeq->parse(t) != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the DeclSeq object
 * Return: SUCCESS or ERROR
 */
int DeclSeq::execute()
{
    /* Execute the declaration */
    if (DeclSeq::decl->execute() != SUCCESS)
        return ERROR;
    
    /* Execute the declaration sequence */
    if (DeclSeq::option == 1)
    {
        if (DeclSeq::declSeq->execute() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the DeclSeq object
 * Return: SUCCESS or ERROR
 */
int DeclSeq::print()
{
    /* Print the declaration  */
    if (DeclSeq::decl->print() != SUCCESS)
        return ERROR;
    
    /* Print the declaration sequence */
    if (DeclSeq::option == 1)
    {
        if (DeclSeq::declSeq->print() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

