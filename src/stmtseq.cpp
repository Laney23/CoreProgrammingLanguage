//
//  stmtseq.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/stmtseq.hpp"

using namespace std;

static bool isStmt(int value);


/*
 * Name: StmtSeq destructor
 * Purpose: Destroy the StmtSeq object
 */
StmtSeq::~StmtSeq()
{
    delete st;
    if(option == 1)
        delete stsq;
} /* function StmtSeq destructor */


/*
 * Name: parse
 * Purpose: parse the StmtSeq object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int StmtSeq::parse(Tokenizer *t)
{
    /* Check the first token */
    TokenPair p = t->front();
    
    /* Call parse on statement object */
    if (isStmt(p.value))
    {
        st = new Stmt;
        if (st->parse(t) != SUCCESS)
            return ERROR;
    }
    else
    {
        cout << p.token << " is an invalid Statment Sequence. Consult the CFG.\n";
        return ERROR;
    }
    
    /* Check if following token is a Statement Sequence as well */
    p = t->front();
    if (isStmt(p.value))
    {
        option = 1;
        stsq = new StmtSeq;
        if (stsq->parse(t) != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the StmtSeq object
 * Return: SUCCESS or ERROR
 */
int StmtSeq::execute()
{
    /* Execute the statement */
    if (st->execute() != SUCCESS)
        return ERROR;
    
    /* Execute the declaration sequence */
    if (option == 1)
    {
        if (stsq->execute() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the StmtSeq object
 * Return: SUCCESS or ERROR
 */
int StmtSeq::print()
{
    /* Print the statement with correct number of tabs  */
    if (st->print() != SUCCESS)
        return ERROR;
    
    /* If it's part of a statement sequence, print the statement sequence */
    if (option == 1)
    {
        if (stsq->print() != SUCCESS)
            return ERROR;
    }
    
    return SUCCESS;
} /* function print */


/*
 * Name: isStmt
 * Purpose: checks if the token is a statement token (if, while, read, write, identifier)
 * Parameters: int value        token value
 * Return: true or false
 */
static bool isStmt(int value)
{
    switch (value) {
        case 5:         /* if */
        case 8:         /* while */
        case 10:       /* read */
        case 11:       /* write */
        case 32:       /* identifier */
            return true;
            break;
            
        default:
            return false;
            break;
    }
} /* function isStmt */

