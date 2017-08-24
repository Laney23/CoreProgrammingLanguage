//
//  fact.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef fact_hpp
#define fact_hpp


#include "../include/parse.hpp"
#include "../include/op.hpp"


class Op;
class Fact : ParseObject {
    int option;
    Fact *f;
    Op *op;
    
public:
    Fact() : option(0) { };
    ~Fact();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* fact_hpp */
