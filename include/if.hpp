//
//  if.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef if_hpp
#define if_hpp


#include "../include/parse.hpp"
#include "../include/cond.hpp"
#include "../include/stmtseq.hpp"


class StmtSeq;

class Iff  : ParseObject {
    int option;
    Cond *cond;
    StmtSeq *ss1;
    StmtSeq *ss2;
    
public:
    Iff() : option(0) { };
    ~Iff();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* if_hpp */
