//
//  loop.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef loop_hpp
#define loop_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "cond.hpp"
#include "stmtseq.hpp"


class Loop : ParseObject {
    Cond c;
    StmtSeq ss;
    
public:
    int parse(Tokenizer &t);
    Loop() : c(Cond()), ss(StmtSeq()) {};
    int execute();
    int print();
};


#endif /* loop_hpp */
