//
//  comp.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef comp_hpp
#define comp_hpp


#include "../include/parse.hpp"
#include "../include/op.hpp"
#include "../include/compop.hpp"


class Comp : ParseObject {
    Op *op1;
    Op *op2;
    CompOp *cop;
    
public:
    Comp() { };
    ~Comp() { delete op1; delete op2; delete cop; }
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* comp_hpp */
