//
//  stmtseq.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef stmtseq_hpp
#define stmtseq_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "stmt.hpp"


class Stmt;
class StmtSeq : ParseObject {
    int option;
    Stmt *st;
    StmtSeq *stsq;
    
public:
    StmtSeq() : option(0), st(new Stmt()) {};
    ~StmtSeq() { delete st; if(option == 1) delete stsq; }
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* stmtseq_hpp */
