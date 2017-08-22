//
//  op.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef op_hpp
#define op_hpp


#include "parse.hpp"
#include "id.hpp"
#include "int.hpp"
#include "exp.hpp"


class Exp;

class Op : ParseObject {
    int option; 
    Int *i;
    Id *id;
    Exp *e;
    
public:
    Op() : option(0) {};
    ~Op();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* op_hpp */
