/*
*  main.cpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#include <iostream>
#include "tokenizer.hpp"
#include "base.hpp"

int main(int argc, const char * argv[])
{
    std::map<char,int> token_values;
    if (initMap(token_values) != 0) return ERROR;
    
    std::cout << "Hello, World!\n";
    return 0;
}
