//
//  program.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef program_hpp
#define program_hpp


#include <string>
#include "../include/parse.hpp"
#include "../include/declseq.hpp"
#include "../include/stmtseq.hpp"


class Program : public ParseObject {
    DeclSeq *ds;
    StmtSeq *ss;
    
public:
    Program() { };
    ~Program() { delete ds; delete ss; }
    int parse(Tokenizer *t);
    int execute();
    int print();
    
};


#endif /* program_hpp */
