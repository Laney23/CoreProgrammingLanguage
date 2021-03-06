//
//  decl.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/decl.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the Decl object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Decl::parse(Tokenizer *t)
{
    /* Remove the first token ('int') */
    TokenPair p = t->getToken();
    if (p.value != INT)
    {
        cout << "Expected keyword: int.\n";
        return ERROR;
    }
    
    /* Parse the IdList */
    if (iList->parse(t) != SUCCESS)
        return ERROR;
    
    /* Verify next token */
    p = t->getToken();
    if (p.value != SEMIC)
    {
        cout << "Semicolon expected.\n";
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
    if (iList->setId(0) != SUCCESS)
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
    cout << "\tint " << iList->getIdNames() << ";\n";
    
    return SUCCESS;
} /* function print */

