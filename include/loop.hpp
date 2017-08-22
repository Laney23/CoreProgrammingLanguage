//
//  loop.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef loop_hpp
#define loop_hpp


#include "parse.hpp"
#include "cond.hpp"
#include "stmtseq.hpp"


class StmtSeq;

class Loop : ParseObject {
    Cond *c;
    StmtSeq *ss;
    
public:
    Loop() { };
    ~Loop();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* loop_hpp */
