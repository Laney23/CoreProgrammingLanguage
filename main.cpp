/*
*  main.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include "tokenizer.hpp"
#include "base.hpp"
#include "parse.hpp"
#include "program.hpp"

using namespace std;

bool ParseObject::inDecSeq = true;
int ParseObject::indent = 0;
extern std::vector<TableElement> idTable;

int main(int argc, const char * argv[])
{
    /* Exit program if incorrect amount of arguments given */
    if (argc != 3) return ERROR;

    /* Initialize variables */
    idTable.reserve(100);
    Tokenizer *toke = new Tokenizer(argv[1]);
    
    /* Tokenize */
    if(toke->tokenize() != SUCCESS) return ERROR;
    toke->print();
    
    /* Parse tokens */
    Program program = Program();
    if (program.parse(toke) != SUCCESS)
    {
        delete toke;
        return ERROR;
    }

    /* Delete tokenizer object after parsing */
    delete toke;
    
    /* Print outputs */
    if (program.print() != SUCCESS)
        return ERROR;
printf("Finished printing.\n");
//TODO: Figure out standardized error messages
    /* Execute program */
    if (program.execute() != SUCCESS)
        return ERROR;

    cout << "Hello, World!\n";
    
    
    return 0;
}
