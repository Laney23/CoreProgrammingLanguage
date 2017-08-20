//
//  comp.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef comp_hpp
#define comp_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "op.hpp"
#include "compop.hpp"


class Comp : ParseObject {
    Op op1;
    Op op2;
    CompOp cop;
    
public:
    int parse(Tokenizer &t);
    Comp() : op1(Op()), op2(Op()), cop(CompOp()) {};
    int execute();
    int print();
};


#endif /* comp_hpp */
