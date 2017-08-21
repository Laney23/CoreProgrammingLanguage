/*
*  tokenizer.cpp
*  CoreProgrammingLanguage
*
* This class ensures that all tokens in the CORE program are valid
* and places them in a vector of TokenPairs. The parser will then
* ask for tokens from the Tokenizer object, which will be returned.
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include "tokenizer.hpp"
using namespace std;


static inline bool isInteger(const std::string & s);
static inline bool is_not_alnum(char c);
static bool string_is_valid(const std::string &str);
static bool firstUpper(const std::string& word);


/*
 * Name: Tokenizer constructor
 * Purpose: initializes class values
 * Parameters:  string file_name                 file name of core program
 */
Tokenizer::Tokenizer(string file_name)
{
    /* Initialize variables */
    cursor = 0;
    token_lookup_table =
    {
        {"program", 1}, {"begin", 2}, {"end", 3}, {"int", 4}, {"if", 5},
        {"then", 6}, {"else", 7}, {"while", 8}, {"loop", 9}, {"read", 10},
        {"write", 11}, {";", 12}, {",", 13}, {"=", 14}, {"!", 15}, {"[", 16},
        {"]", 17}, {"&&", 18}, {"||", 19}, {"(", 20}, {")", 21}, {"+", 22},
        {"-", 23}, {"*", 24}, {"!=", 25}, {"==", 26}, {"<", 27}, {">", 28},
        {"<=", 29}, {">=", 30}, {"NUMBER", 31}, {"IDENTIFIER", 32}, {"EOF", 33}
    };
    tokens.reserve(100);            /* initially reserve space for 100 tokens */
    
    /* Perform file operations */
    processFileArgument(file_name);
} /* function Tokenizer constructor */


/*
* Name: tokenize
* Purpose: tokenizes the given core program file into the CORE token values
* Parameters:  ifstream& core_program                 file stream of core program
* Return: SUCCESS or ERROR
*/
int Tokenizer::tokenize()
{
    /* Make sure constructor successfully opened file */
    if (!core_program.is_open()) return ERROR;
        
    /* Tokenize file line by line */
    string line;
    //TODO: What if program is in all capitals?
    while (getline(core_program, line)) {
        if(tokenizeLine(line) != SUCCESS) return ERROR;
    }
        
    /* Add EOF token */
    TokenPair pair = { 33, "EOF" };
    tokens.push_back(pair);
    
    /* Close input file */
    core_program.close();
        
    return SUCCESS;
} /* function tokenize */


/*
* Name: tokenizeLine
* Purpose: tokenizes a given line and appends their values to Tokenizer::tokens
* Parameters: const string& str                                                     line to tokenize
* Return: SUCCESS or ERROR
* NOTE: Function adapted from http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
*/
int Tokenizer::tokenizeLine(const string& str)
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
        // TODO : Check lowercase here
        auto value = token_lookup_table.find(token.c_str());
            
        /* Token is a value in th lookup table */
        if(value != token_lookup_table.end())
                pair.value = value->second;
        else if (firstUpper(token))  /* Token is an identifier */
        {
                /* Check if rest of word contains capital letters and/or digits */
                if (token.length() > 1 && !string_is_valid(token))
                {
                        printf("Token %s is an invalid identifier. Please consult the CFG.\n", token.c_str());
                        return ERROR;
                }
                    pair.value = 32;
        }
        else if (isInteger(token)) /* Token is a number */
            pair.value = 31;
        else /* badly formatted */
        {
            printf("Token %s is invalid. Please consult the CFG.\n", token.c_str());
            return ERROR;
        }
            
        /* Add TokenPair into the storage vector */
        pair.token = token;
        tokens.push_back(pair);
            
        /* Skip delimiters.  Note the "not_of" */
        lastPos = str.find_first_not_of(DELIMS_, pos);
        /* Find next "non-delimiter" */
        pos = str.find_first_of(DELIMS_, lastPos);
    }
        
    return SUCCESS;
} /* function tokenizeLine */


/*
 * Name: processFileArgument
 * Purpose: Processes and validates the file argument
 * Parameters: string file_nam         name of file to open
 * Return: SUCCESS or ERROR
 */
int Tokenizer::processFileArgument(string file_name)
{
    /* Verify file exists in current directory */
    struct stat buffer;
    if (stat (file_name.c_str(), &buffer) != 0)
    {
        printf("File does not exist in current directory");
        return ERROR;
    }
    
    /* Open file for processing */
    core_program.open(file_name, ios::in);
    
    /* Verify file is opened */
    if(core_program.is_open())
        return SUCCESS;
    
    return ERROR;
} /* function processFileArgument */


/*
 * Name: print
 * Purpose: Prints all tokens in the Tokenizer::tokens vector
 */
void Tokenizer::print()
{
    int i = 0;
    printf("Number of tokens: %lu\n", tokens.size());
    printf("================\n");
    while (i < tokens.size()) {
        TokenPair x = tokens.at(i++);
        printf("Value: %i\t\tToken: %s\n", x.value, x.token.c_str());
    }
} /* function print */


/*
 * Name: getToken
 * Purpose: returns the token at the front of the vector
 * Return: the first token or empty TokenPair if out of tokens
 */
TokenPair Tokenizer::getToken()
{
    if (cursor < tokens.size())
        return tokens.at(cursor++);
    
    printf("Out of tokens");
    return { 0, "0" };
} /* function getToken */


/*
 * Name: skipToken
 * Purpose: gives the token value of the second token without
 *                 incrementing the cursor
 * Return: the second token or empty TokenPair if out of tokens
 */
TokenPair Tokenizer::skipToken()
{
    if (cursor+1 < tokens.size())
        return tokens.at(cursor+1);

    printf("Out of tokens");
    return { 0, "0" };
} /* function skipToken */


/*
 * Name: intVal
 * Purpose: gives the integer value of the token
 * Return: the token value
 * NOTE: Can only be called on integers 
 */
int Tokenizer::intVal()
{
    TokenPair p = tokens.at(cursor);
    /* Verify string is integer */
    if(!isInteger(p.token))
    {
        printf("Function intVal() can only be called on integers. Calling on token: %s\n", p.token.c_str());
        return ERROR;
    }
    
    /* Convert string value */
    return stoi(p.token);
} /* function intVal */


/*
 * Name: idName
 * Purpose: gives the string value of the token
 * Return: the string token
 */
string Tokenizer::idName()
{
    TokenPair p = tokens.at(cursor);
    return p.token;
} /* function idName */


/*
 * Name: totalTokens
 * Purpose: gives the total number of tokens
 * Return: the total number of tokens
 */
inline int Tokenizer::totalTokens()
{
    return (int)tokens.size();
} /* function totalTokens */


/*
 * Name: front
 * Purpose: gives the first token without incrementing the cursor
 * Return: the first token
 */
TokenPair Tokenizer::front()
{
    if (cursor < tokens.size())
        return tokens.at(cursor);
    else
    {
        printf("Out of tokens.\n");
        return { 0, "0" };
    }
} /* function front */


/* PRIVATE FUNCTIONS */


/*
 * Name: isInteger
 * Purpose: verifies that a string is an integer
 * Parameters: const string &s                    string to verify
 * Return: True or false if the character is a valid identifier
 * NOTE: Function taken from https://stackoverflow.com/a/2845275/2127502
 */
static inline bool isInteger(const string &s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
        
    char * p ;
    strtol(s.c_str(), &p, 10) ;
        
    return (*p == 0) ;
} /* function isInteger */
    

/*
 * Name: is_not_alnum
 * Purpose: verifies that a character is capital alphanumeric
 * Parameters: char c                                character to verify
 * Return: True or false if the character is a valid identifier
 * NOTE: Function taken from https://stackoverflow.com/q/2926878/2127502
 */
static  inline bool is_not_alnum(char c)
{
    return !((isalpha(c) && isupper(c)) || isdigit(c));
} /* function is_not_alnum */
    

/*
 * Name: string_is_valid
 * Purpose: verifies that every letter in a string is capital alphanumeric
 * Parameters: const string& str                                      string to verify
 * Return: True or false if the string is a valid identifier
 * NOTE: Function taken from https://stackoverflow.com/q/2926878/2127502
 */
static bool string_is_valid(const string &str)
{
    return find_if(str.begin(), str.end(), is_not_alnum) == str.end();
} /* function string_is_valid */


/*
 * Name: firstUpper
 * Purpose: checks if the first character of a string is uppercase
 * Parameters: const string& word                       string to verify
 * Return: True or false if the first letter is uppercase
 * NOTE: Function taken from https://stackoverflow.com/a/14305515/2127502
 */
static inline bool firstUpper(const string &word)
{
    return (word.size() && isupper(word[0]));
} /* function firstUpper */
