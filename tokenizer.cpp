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
static int tokenizeLine(const std::map<std::string,int> token_lookup_table, const std::string& line);


/*
 * Name: tokenize
 *
 * Purpose: tokenizes the given core program file into the given mapped token values
 *
 * Parameters:  const std::map<std::string,int> token_lookup_table        token values table
 *                       std::ifstream& core_program                                            file stream of core program
 *
 * Return: SUCCESS or ERROR
 */
int tokenize(const std::map<std::string,int> token_lookup_table, std::ifstream& core_program, std::vector<int> token_values_list)
{
    if (!core_program.is_open()) return ERROR;
    
    /* Tokenize file line by line */
    string line;
    while (getline(core_program, line)) {
        if(tokenizeLine(token_lookup_table, line) != SUCCESS) return ERROR;
    }
    
    
    return SUCCESS;
} /* function tokenize */


static int tokenizeLine(const std::map<std::string,int> token_lookup_table, const std::string& line, std::vector<int> token_values_list)
{
    char *token = std::strtok(line, DELIMS_);
    
    while (token)
    {
        /* if the token is in the lookup table, add the token to the values array */
        if (token_lookup_table.find(token) != token_lookup_table.end())
            token_values_list.push_back(*token);
        
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





