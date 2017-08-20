//
//  if.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "if.hpp"


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
    if (Iff::condition->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove "then" */
    p = t->getToken();
    if(p.value != THEN)
    {
        printf("Expected reserved word: then, found: %s\n", p.token.c_str());
        return ERROR;
    }
    
    /* Parse the statement sequence */
    if (Iff::ss1->parse(t) != SUCCESS)
        return ERROR;
    
    /* Check for else statement */
    p = t->front();
    if (p.value == ELSE)
    {
        Iff::option = 1;
        /* Remove 'else' */
        p = t->getToken();
        Iff::ss2 = new StmtSeq();
        if (Iff::ss2->parse(t) != SUCCESS)
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
    if (Iff::cond->execute() == true)
    {
        /* If the condition is true, execute the statement sequence */
        if (Iff::ss1->execute() != SUCCESS)
            return ERROR;
    }
    /* if this is an if/then/else statement, execute the second statement sequence */
    else if (Iff::option == 1)
    {
        if (Iff::ss2->execute() != SUCCESS)
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
    std::string str = std::string(++ParseObject::indent, "\t");
    str += "if ";
    printf("%s", str.c_str());
    
    /* Print condition */
    if (Iff::condition->print() != SUCCESS)
        return ERROR;
    
    /* Print 'then' */
    printf(" then\n");
    
    /* Print statement sequence */
    if (Iff::ss1->print() != SUCCESS)
        return ERROR;
    
    /* Print else if necessary */
    if (Iff::option == 1)
    {
        printf("\n");
        std::string str = std::string(ParseObject::indent, "\t");
        str += "else\n";
        printf("%s", str.c_str());
        
        /* Print statement sequence */
        if (Iff::ss2->print() != SUCCESS)
            return ERROR;
    }
    
    /* Print 'end' */
    printf("\n");
    std::string str = std::string(ParseObject::indent--, "\t");
    str += "end;";
    printf("%s\n", str.c_str());
    
    
    return SUCCESS;
} /* function print */


