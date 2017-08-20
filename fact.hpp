//
//  fact.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef fact_hpp
#define fact_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "op.hpp"

class Op;
class Fact : ParseObject {
    int option;
    Fact *f;
    Op *op;
    
public:
    Fact() : option(0), op(new Op()) {};
    ~Fact() { delete op; if(option == 1) delete fact; }
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* fact_hpp */
