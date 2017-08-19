//
//  tokenizer.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <sys/stat.h>
#include <vector>
#include "base.hpp"


#define DELIMS_  " \f\n\r\t\v"


struct TokenPair
{
    int value;
    std::string token;
};


class Tokenizer {
    std::vector<TokenPair> tokens;
    std::map<std::string,int> token_lookup_table;
    std::ifstream core_program;
    
public:
    Tokenizer(std::string file_name);
    int tokenize();
    int tokenizeLine(const std::string& str);
    int processFileArgument(std::string file_name);
    int print();
    int getToken();
    int skipToken();
    int intVal();
    int idName();
};


#endif /* tokenizer_hpp */
