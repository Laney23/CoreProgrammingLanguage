/*
*  main.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/
//TODO: includes need to be in each file

#include "tokenizer.hpp"
#include "base.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    /* Exit program if correct amount of arguments given */
    if (argc != 3) return ERROR;

    /* Initialize variables */
    Tokenizer toke = Tokenizer(argv[1]);
    
    /* Tokenize */
    if(toke.tokenize() != SUCCESS) return ERROR;
    toke.print();
    
    /* Parse tokens */
    
    
    /* Print outputs */
    
    cout << "Hello, World!\n";
    
    
    return 0;
}
