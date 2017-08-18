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
    /* Exit program if correct input file amount isn't given */
    if (argc != 3) return ERROR;

    /* Initialize variables */
    ifstream core_program;
    if(processFileArgument(argv[1], core_program) != SUCCESS) return ERROR;
    vector<TokenPair> token_values_list;             /* vector to hold token values */
    token_values_list.reserve(100);            /* initially reserve space for 100 tokens */
    map<string,int> token_lookup_table;   /* map of corresponding token values */
    if (initMap(token_lookup_table) != SUCCESS) return ERROR;
    
//    for(auto it = token_lookup_table.cbegin(); it != token_lookup_table.cend(); ++it)
//        printf("K: %s\tV: %d\n", it->first.c_str(), it->second);
//   
    
    /* Tokenize */
    if(tokenize(token_lookup_table, core_program, token_values_list) != SUCCESS)
    {
        core_program.close();
        return ERROR;
    }
    else
        core_program.close();
    
    int i = 0;
    printf("length: %lu\n", token_values_list.size());
    printf("============\n");
    while (i < token_values_list.size()) {
        TokenPair x = token_values_list.at(i++);
        printf("%i\t%s\n", x.value, x.token.c_str());
    }
    
    /* Parse tokens */
    
    
    /* Print outputs */
    
    cout << "Hello, World!\n";
    
    /* Close file descriptor */
    // TODO: May be irrelevant now
    if(tearDown(core_program) != SUCCESS) return ERROR;
    
    return 0;
}
