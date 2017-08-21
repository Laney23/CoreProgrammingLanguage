//
//  if.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "if.hpp"


//TODO: comment these

Iff::~Iff()
{
    delete cond;
    delete ss1;
    if(option == 1)
        delete ss2;
}

/*
 * Name: parse
 * Purpose: parse the Iff object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Iff::parse(Tokenizer *t)
{
    /* Initialize variables */
    TokenPair p = t->getToken();
    
    /* Remove "if" */
    if(p.value != IF)
    {
        printf("Expected reserved word: if, found: %s\n", p.token.c_str());
        return ERROR;
    }
    
    /* Parse the condition */
    cond = new Cond;
    if (cond->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove "then" */
    p = t->getToken();
    if(p.value != THEN)
    {
        printf("Expected reserved word: then, found: %s\n", p.token.c_str());
        return ERROR;
    }
    
    /* Parse the statement sequence */
    ss1 = new StmtSeq;
    if (ss1->parse(t) != SUCCESS)
        return ERROR;
    
    /* Check for else statement */
    p = t->front();
    if (p.value == ELSE)
    {
        option = 1;
        /* Remove 'else' */
        p = t->getToken();
        ss2 = new StmtSeq;
        if (ss2->parse(t) != SUCCESS)
            return ERROR;
    }
    
    /* Remove 'end */
    p = t->getToken();
    if(p.value != END)
    {
        printf("Expected reserved word: end, found: %s\n", p.token.c_str());
        return ERROR;
    }
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        printf("Expected semicolon\n");
        return ERROR;
    }
        
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Iff object
 * Return: SUCCESS or ERROR
 */
int Iff::execute()
{
    /* Execute the condition */
    if (cond->execute() == true)
    {
        /* If the condition is true, execute the statement sequence */
        if (ss1->execute() != SUCCESS)
            return ERROR;
    }
    /* if this is an if/then/else statement, execute the second statement sequence */
    else if (option == 1)
    {
        if (ss2->execute() != SUCCESS)
            return ERROR;
    }

    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Iff object
 * Return: SUCCESS or ERROR
 */
int Iff::print()
{
    /* Print 'if' with correct indentation */
    printf("%*s""if ", ++indent, "\t");
    
    /* Print condition */
    if (cond->print() != SUCCESS)
        return ERROR;
    
    /* Print 'then' */
    printf(" then\n");
    
    /* Print statement sequence */
    if (ss1->print() != SUCCESS)
        return ERROR;

    /* Print else if necessary */
    if (option == 1)
    {
        printf("\n%*s""else\n", indent, "\t");
        
        /* Print statement sequence */
        if (ss2->print() != SUCCESS)
            return ERROR;
    }
    
    /* Print 'end' */
    printf("%*s""end;\n", --indent, "\t");
    
    return SUCCESS;
} /* function print */


