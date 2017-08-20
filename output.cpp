//
//  output.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "output.hpp"


static std::vector<std::string> split(const std::string &text, char sep);


/*
 * Name: Output constructor
 * Purpose: initializes class values
 */
Output::Output()
{
    /* Initialize variables */
    Output::iList = IdList();
} /* function Loop constructor */


/*
 * Name: parse
 * Purpose: parse the Output object
 * Return: SUCCESS or ERROR
 */
int Output::parse(Tokenizer &t)
{
    /* Remove 'while' */
    TokenPair p = t.getToken();
    if(p.value != WRITE)
    {
        printf("Expected write keyword\n");
        return ERROR;
    }
    
    /* Parse the condition */
    if (Output::iList.parse(&t) != SUCCESS)
        return ERROR;
    
    /* Remove ';' */
    p = t.getToken();
    if(p.value != SEMIC)
    {
        printf("Missing ;\n");
        return ERROR;
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Output object
 * Return: SUCCESS or ERROR
 */
int Output::execute()
{
    /* Get list of identifiers */
    std::string s = Output::iList.getNames();
    
    /* Split the string by comma delimeter and lookup each item */
    std::vector<std::string> ids = split(&s, ",");
    int count = 0;
    while (count < ids.size())
    {
        int index = ParseObject::inTable(ids[count++]);
        TableElement te = ParseObject::idTable.at(index);
        
        if (index == ERROR)
        {
            printf("Variable was never declared.\n");
            return ERROR;
        }
        else if (te.isInit)
            printf("%s = %d\n", te.idName.c_str(), te.idVal);
        else
        {
            printf("Variable was never initialized.\n");
            return ERROR;
        }
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Output object
 * Return: SUCCESS or ERROR
 */
int Output::print()
{
    /* Print 'while' with correct indentation */
    std::string str = std::string(++ParseObject::indent, "\t");
    str += "write ";
    printf("%s", str.c_str());
    
    /* Print the id list */
    if (Output::iList.print() != SUCCESS)
        return ERROR;
    
    /* Print ';' */
    printf(";\n");
    
    /* Reset indentation */
    ParseObject::indent--;
    
    return SUCCESS;
} /* function print */


//TODO: fill out this comment section
// https://stackoverflow.com/a/7408245/2127502
static std::vector<std::string> split(const std::string &text, char sep)
{
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
} /* function split */

