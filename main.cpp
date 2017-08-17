/*
*  main.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include "tokenizer.hpp"
#include "base.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    if (argc != 3) return ERROR;
    
    /* Initialize variables */
    ifstream core_program;
    if(processFileArgument(argv[1], core_program) != SUCCESS) return ERROR;
    vector<int> token_values_list;             /* vector to hold token values */
    token_values_list.reserve(100);            /* initially reserve space for 100 tokens */
    map<string,int> token_lookup_table;   /* map of corresponding token values */
    if (initMap(token_lookup_table) != SUCCESS) return ERROR;
    
    cout << "Hello, World!\n";
    return 0;
}
