//
//  stmtseq.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef stmtseq_hpp
#define stmtseq_hpp


#include "../include/parse.hpp"
#include "../include/stmt.hpp"


class Stmt;

class StmtSeq : ParseObject {
    int option;
    Stmt *st;
    StmtSeq *stsq;
    
public:
    StmtSeq() : option(0) { };
    ~StmtSeq();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* stmtseq_hpp */
