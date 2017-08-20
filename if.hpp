//
//  if.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef if_hpp
#define if_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "cond.hpp"
#include "stmtseq.hpp"


class Iff  : ParseObject {
    int option;
    Cond condition;
    StmtSeq ss1;
    StmtSeq ss2;
    
public:
    Iff();
    int parse(Tokenizer &t);
    int execute();
    int print();
};


#endif /* if_hpp */
