//
//  tokenizer.cpp
//  CoreProgrammingLanguage
//
// This class ensures that all tokens in the CORE program are valid
// and returns them in a vector of TokenPairs
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "tokenizer.hpp"
using namespace std;

/* Static function prototypes */
static int tokenizeLine(const std::map<std::string,int> token_lookup_table, const string& str, vector<TokenPair>& token_values_list);
static inline bool isInteger(const std::string & s);
static inline bool is_not_alnum_space(char c);
static bool string_is_valid(const std::string &str);


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
    
    /* Add EOF token */
    TokenPair pair = { 33, "EOF" };
    token_values_list.push_back(pair);
    
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
        TokenPair pair;
        
        /* Found a token, add it to the vector */
        string token = str.substr(lastPos, pos - lastPos);
        auto value = token_lookup_table.find(token.c_str());

        /* Token is a value in th lookup table */
        if(value != token_lookup_table.end())
            pair.value = value->second;
        else if (firstUpper(token))  /* Token is an identifier */
        {
            /* Check if rest of word contains capital letters and/or digits */
            if (token.length() > 1 && !string_is_valid(token))
            {
                printf("Token %s is an invalid identifier. Please consult the context free grammar.\n", token.c_str());
                return ERROR;
            }
            pair.value = 32;
        }
        else if (isInteger(token)) /* Token is a number */
            pair.value = 31;
        else /* badly formatted */
        {
            printf("Token %s is invalid. Please consult the context free grammar.\n", token.c_str());
            return ERROR;
        }
        
        /* Add TokenPair into the storage vector */
        pair.token = token;
        token_values_list.push_back(pair);
        
        /* Skip delimiters.  Note the "not_of" */
        lastPos = str.find_first_not_of(DELIMS_, pos);
        /* Find next "non-delimiter" */
        pos = str.find_first_of(DELIMS_, lastPos);
    }
    
    return SUCCESS;
} /* function tokenizeLine */

/* Taken from: https://stackoverflow.com/a/2845275/2127502 */
static inline bool isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    
    return (*p == 0) ;
}


/* Taken from: https://stackoverflow.com/q/2926878/2127502 */
static inline bool is_not_alnum_space(char c)
{
    return !((isalpha(c) && isupper(c)) || isdigit(c));
}


static bool string_is_valid(const std::string &str)
{
    return find_if(str.begin(), str.end(), is_not_alnum_space) == str.end();
}


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





