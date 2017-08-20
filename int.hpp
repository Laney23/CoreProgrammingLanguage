//
//  int.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef int_hpp
#define int_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"


class Int : ParseObject {
    int value;
    
public:
    Int();
    int parse(Tokenizer &t);
    int execute();
    int print();
};


#endif /* int_hpp */
