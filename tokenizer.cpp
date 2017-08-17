//
//  tokenizer.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "tokenizer.hpp"

#define DELIMS_  " \f\n\r\t\v"

class Tokenizer
{
    private:
        char* tokens;
    
    protected:
        void emit();
        void accept(char c);
        void reject();
    

};

int tokenizeLine(const std::string& line)
{
    int counter = 0;
    
    /* Set up token array */
    const int line_length = line.size();
    char *token_values = new char[line_length];
    
    char *token = strtok((char*)line.c_str(), DELIMS_);
    
    while (token)
    {
        token_values[counter++] = *token;
        token = strtok(NULL, DELIMS_);
    }
    
    return 0;
};


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





