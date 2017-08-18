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
#include <string>
#include <array>
#include "base.hpp"

int tokenize(const std::map<std::string,int> token_lookup_table, std::ifstream& core_program, std::vector<TokenPair>& token_values_list);
int getToken();
int skipToken();
int intVal();
int idName();


#endif /* tokenizer_hpp */
