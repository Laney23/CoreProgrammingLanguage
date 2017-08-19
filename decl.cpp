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
Decl::Decl()
{
    /* Initialize variables */
    Decl::iList = IdList();
}; /* function Decl constructor */


/*
 * Name: parse
 * Purpose: parse the Decl object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Decl::parse(Tokenizer t)
{
    /* Remove the first token ('int') */
    t.getToken();
    
    /* Parse the IdList */
    if (Decl::iList.parse() != SUCCESS)
        return ERROR;
    
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
 * Return: SUCCESS 
 */
int Decl::execute()
{
    /* 
     * Set all values to 0 initially. The isInit value will determine if the variable has actually
     * been set. This will just add the variable to the lookup table
     */
    if (Decl::iList.setId(0) != SUCCESS)
        return ERROR;
     
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Decl object
 * Return: SUCCESS or ERROR
 */
int Decl::print()
{
    printf("\tint ");
    printf("%s", Decl::iList.getIdNames());
    printf(";\n");
    
    return SUCCESS;
} /* function print */

