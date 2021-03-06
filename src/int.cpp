//
//  int.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/int.hpp"

using namespace std;

/*
 * Name: parse
 * Purpose: parse the Int object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Int::parse(Tokenizer *t)
{
    /* Verify the integer token  */
    TokenPair p = t->front();
    if(p.value != NUMBER)
    {
        cout << "Expected a number.\n";
        return ERROR;
    }

    /* Parse integer */
    value = t->intVal();
    
    /* Remove number token */
    t->getToken();
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Int object
 * Return: The evaluated value of the factor
 */
int Int::execute()
{
    return value;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Int object
 * Return: SUCCESS or ERROR
 */
int Int::print()
{
    /* Print the integer */
    cout <<  value;
    
    return SUCCESS;
} /* function print */

