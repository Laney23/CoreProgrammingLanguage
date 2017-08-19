//
//  decl.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "decl.hpp"


/*
 * Name: Decl constructor
 * Purpose: initializes class values
 * Parameters:  Tokenizer toke                 tokenizer object to parse
 */
Decl::Decl(Tokenizer toke)
{
    /* Initialize variables */
    DeclSeq::iList = IdList(toke);
}; /* function Decl constructor */


/*
 * Name: parse
 * Purpose: parse the Decl object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int parse(Tokenizer t)
{
    /* Remove the first token ('int') */
    t.getToken();
    
    /* Parse the IdList */
    Decl::iList.parse();
    
    /* Verify next token */
    TokenPair p = t.getToken();
    if (p.token.compare(";") != 0)
    {
        printf("Semicolon expected.\n");
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Decl object
 * Return: SUCCESS or ERROR
 */
int execute()
{

    /*
     def execute(self):
     # Set the initial value of the variable to None
     self.iList.setId(None)
     */
     
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Decl object
 * Return: SUCCESS or ERROR
 */
int print()
{
    printf("\tint ");
    Decl::iList.print();
    printf(";");
    
    return SUCCESS;
} /* function print */
