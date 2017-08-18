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
static int tokenizeLine(const std::map<std::string,int> token_lookup_table, const string& str, vector<TokenPair>& token_values_list);


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
int tokenize(const std::map<std::string,int> token_lookup_table, std::ifstream& core_program, std::vector<TokenPair>& token_values_list)
{
    if (!core_program.is_open()) return ERROR;
    
    /* Tokenize file line by line */
    string line;
    while (getline(core_program, line)) {
        if(tokenizeLine(token_lookup_table, line, token_values_list) != SUCCESS) return ERROR;
    }
    
    return SUCCESS;
} /* function tokenize */


/*
 * Name: tokenizeLine
 *
 * Purpose: tokenizes a given line and appends their values to token_values_list
 *
 * Parameters:
 *
 * Return: SUCCESS
 * NOTE: Function adapted from http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html 
 */
static int tokenizeLine(const std::map<std::string,int> token_lookup_table, const string& str, vector<TokenPair>& token_values_list)
{
    /* Skip delimiters at beginning */
    string::size_type lastPos = str.find_first_not_of(DELIMS_, 0);
    /* Find first "non-delimiter" */
    string::size_type pos     = str.find_first_of(DELIMS_, lastPos);
    
    while (string::npos != pos || string::npos != lastPos)
    {
        /* Found a token, add it to the vector */
        string token = str.substr(lastPos, pos - lastPos);
        printf("\nstring: %s", token.c_str());
        auto value = token_lookup_table.find(token.c_str());
 //TODO: Figure out tokenizing identifiers and numbers
        if(value != token_lookup_table.end())
        {
            TokenPair pair;
            pair.value = value->second;
            pair.token = token;
            token_values_list.push_back(pair);
            printf("\ttoken: %i\n", value->second);
        }
//        else if (<#condition#>) //identifier
//        {
//            
//        }
//        else if () //number
//        {
//            
//        }
        else /* badly formatted */
        {
            ;//return ERROR;
        }
        
        /* Skip delimiters.  Note the "not_of" */
        lastPos = str.find_first_not_of(DELIMS_, pos);
        /* Find next "non-delimiter" */
        pos = str.find_first_of(DELIMS_, lastPos);
    }
    
    return SUCCESS;
} /* function tokenizeLine */


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





