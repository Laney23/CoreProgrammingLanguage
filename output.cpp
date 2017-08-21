//
//  output.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "output.hpp"

using namespace std;

static std::vector<std::string> splitter(const std::string &text, char sep);

//TODO: comment this
Output::~Output()
{
    delete iList;
}

/*
 * Name: parse
 * Purpose: parse the Output object
 * Return: SUCCESS or ERROR
 */
int Output::parse(Tokenizer *t)
{
    /* Remove 'write' */
    TokenPair p = t->getToken();
    if(p.value != WRITE)
    {
        cout << "Expected write keyword\n";
        return ERROR;
    }
    
    /* Parse the condition */
    iList = new IdList;
    if (iList->parse(t) != SUCCESS)
        return ERROR;
    
    /* Remove ';' */
    p = t->getToken();
    if(p.value != SEMIC)
    {
        cout << "Missing ;\n";
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
    std::string s = iList->getIdNames();
    
    /* Split the string by comma delimeter and lookup each item */
    std::vector<std::string> ids = splitter(s, ',');
    
    int count = 0;
    while (count < ids.size())
    {
        int index = idTable->inTable(ids[count++]);
        if (index == ERROR)
        {
            cout << "Variable was never declared.\n";
            return ERROR;
        }
        
        TableElement te = idTable->getElement(index);
        if (te.isInit)
            cout << te.idName << " = " << te.idVal << endl;
        else
        {
            cout << "Variable was never initialized.\n";
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
    cout << string(indent, '\t') << "write ";
    
    /* Print the id list */
    if (iList->print() != SUCCESS)
        return ERROR;
    
    /* Print ';' */
    cout << ";\n";
    
    return SUCCESS;
} /* function print */



//TODO: fill out this comment section
// https://stackoverflow.com/a/7408245/2127502
std::vector<std::string> splitter(const std::string &text, char sep)
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
