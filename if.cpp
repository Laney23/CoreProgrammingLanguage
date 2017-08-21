//
//  if.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "if.hpp"

using namespace std;

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
        cout << "Expected reserved word: if, found: " << p.token << endl;
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
        cout << "Expected reserved word: then, found: " << p.token << endl;
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
        cout << "Expected reserved word: end, found: " << p.token << endl;
        return ERROR;
    }
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        cout << "Expected semicolon\n";
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
//    printf("%*s""if ", ++indent, "\t");
//    cout << "indent: " << indent << endl;
    cout << string(indent, '\t') << "if ";
    
    /* Print condition */
    if (cond->print() != SUCCESS)
        return ERROR;
    
    /* Print 'then' */
    cout << " then\n";
    
    /* Print statement sequence */
    if (ss1->print() != SUCCESS)
        return ERROR;

    /* Print else if necessary */
    if (option == 1)
    {
//        printf("%*s""else\n", indent, "\t");
        cout << string(indent, '\t') << "else\n";
        
        /* Print statement sequence */
        if (ss2->print() != SUCCESS)
            return ERROR;
    }
    
    /* Print 'end' */
//    printf("%*s""end;\n", indent, "\t");
    cout << string(indent, '\t') << "end;\n";
    
    return SUCCESS;
} /* function print */


