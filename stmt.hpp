//
//  stmt.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef stmt_hpp
#define stmt_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "stmtseq.hpp"
#include "if.hpp"
#include "loop.hpp"
#include "output.hpp"
//#include "input.hpp"
#include "assign.hpp"


class Stmt : ParseObject {
    int option;
    Iff *iff;
    Loop *loop;
//    Input *in;
    Output *out;
    Assign *assign;
    
public:
    Stmt() : option(0) {};
    ~Stmt() { if(option == 1) delete iff; if(option == 2) delete loop; /*if(option == 3) delete in;*/ if(option == 4) delete out; if(option == 5) delete assign; }
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* stmt_hpp */
