//
//  tokenizer.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "tokenizer.hpp"
using namespace std;

#define DELIMS_  " \f\n\r\t\v"

/* Static function prototypes */
int tokenizeLine(const std::map<std::string,int> token_lookup_table, const std::string& line);


int tokenizeLine(const std::map<std::string,int> token_lookup_table, const std::string& line)
{
    int index = 0;
    
    /* Set up token array */
    const int line_length = line.length();
    char *token_values = new char[line_length];
    
    char *token = strtok(line, DELIMS_);
    
    while (token)
    {
        /* if the token is in the lookup table, add the token to the values array */
        if (token_lookup_table.find(token) != token_lookup_table.end())
            token_values[index++] = *token;
        
        token = strtok(NULL, DELIMS_);
    }
    
    return SUCCESS;
}; /* function tokenizeLine */


/*
 * Name: getToken
 *
 * Purpose: returns the first token
 *
 * Parameters:
 *
 * Return:
 */
int getToken()
{
    return 0;
} /* function getToken */


/*
 * Name: skipToken
 *
 * Purpose: skips the first token so that the next token becomes the current token.
 *
 * Parameters:
 *
 * Return:
 */
int skipToken()
{
    return 0;
} /* function skipToken */


/*
 * Name: intVal
 *
 * Purpose: returns the integer value of the current token.
 *
 * Parameters:
 *
 * Return:
 */
int intVal()
{
    return 0;
} /* function intVal */


/*
 * Name: idName
 *
 * Purpose: returns the name of the current token.
 *
 * Parameters:
 *
 * Return:
 */
int idName()
{
    return 0;
} /* function idName */





