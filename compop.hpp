//
//  compop.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef compop_hpp
#define compop_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"


class CompOp : ParseObject {
    int option;
    
public:
    int parse(Tokenizer &t);
    CompOp() : option(0) {};
    int execute();
    int print();
};


#endif /* compop_hpp */
