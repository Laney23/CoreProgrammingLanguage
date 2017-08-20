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


class StmtSeq : ParseObject {
    int option;
    Stmt st;
    StmtSeq stsq;
    
public:
    StmtSeq();
    int parse(Tokenizer &t);
    int execute();
    int print();
};


#endif /* stmtseq_hpp */
