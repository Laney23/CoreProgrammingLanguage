//
//  declseq.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/declseq.hpp"

using namespace std;

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
        cout << "int keyword expected. Got " << p.value << endl;
        return ERROR;
    }
    
    /* Parse declaration */
    if (decl->parse(t) != SUCCESS)
        return ERROR;
    
    /* If the next token is 'int', then this is a sequence. Create the DeclSeq child and parse it */
    p = t->front();
    transform(p.token.begin(), p.token.end(), p.token.begin(), ::tolower);
    if (p.value == INT)
    {
        option = 1;
        declSeq = new DeclSeq;
        if (declSeq->parse(t) != SUCCESS)
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
    if (decl->execute() != SUCCESS)
        return ERROR;
    
    /* Execute the declaration sequence */
    if (option == 1)
    {
        if (declSeq->execute() != SUCCESS)
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
    if (decl->print() != SUCCESS)
        return ERROR;
    
    /* Print the declaration sequence */
    if (option == 1)
    {
        if (declSeq->print() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */

