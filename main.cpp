/*
*  main.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include <iostream>
#include <stdio.h>
#include "tokenizer.hpp"
#include "base.hpp"
#include "program.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    /* Exit program if incorrect amount of arguments given */
    if (argc != 3) return ERROR;

    /* Initialize variables */
    Tokenizer toke = Tokenizer(argv[1]);
    
    /* Tokenize */
    if(toke.tokenize() != SUCCESS) return ERROR;
    toke.print();
    
    /* Parse tokens */
    Program program = Program();
    program.parse(toke);

    /* Print outputs */
    program.print();
//TODO: Figure out standardized error messages
    /* Execute program */
    program.execute();

    cout << "Hello, World!\n";
    
    
    return 0;
}
