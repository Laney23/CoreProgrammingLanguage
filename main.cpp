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
//    Parser parser = Parser(toke);
//
//    /* Print outputs */
//    parser.print();
//
//    /* Execute program */
//    parser.execute();
//
    cout << "Hello, World!\n";
    
    
    return 0;
}
