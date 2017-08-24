/*
*  main.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include <iostream>
#include <vector>
#include "../include/tokenizer.hpp"
#include "../include/table.hpp"
#include "../include/base.hpp"
#include "../include/parse.hpp"
#include "../include/program.hpp"
//#include "../include/catch.hpp"


using namespace std;


bool ParseObject::inDecSeq = true;
int ParseObject::indent = 0;
IdTable *IdTable::table_instance = NULL;


int main(int argc, const char * argv[])
{
    /* Exit program if incorrect amount of arguments given */
    if (argc != 3) return ERROR;

    /* Initialize variables */
    Tokenizer *toke = new Tokenizer(argv[1]);
    
    /* Tokenize */
    printf("Tokenizing...\n");
    if(toke->tokenize() != SUCCESS) return ERROR;
//    toke->print();
    
    /* Parse tokens */
    printf("Parsing...\n");
    Program program = Program();
    if (program.parse(toke) != SUCCESS)
    {
        delete toke;
        return ERROR;
    }

    /* Delete tokenizer object after parsing */
    delete toke;
    
    /* Print outputs */
    printf("Printing...\n");
    if (program.print() != SUCCESS)
        return ERROR;

    //TODO: Figure out standardized error messages
    /* Execute program */
    printf("Executing...\n");
    if (program.execute() != SUCCESS)
        return ERROR;

    return 0;
}
