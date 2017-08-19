//
//  declseq.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef declseq_hpp
#define declseq_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"


class DeclSeq : ParseObject {
    int option;
    Decl decl;
    DeclSeq declSeq;
    
public:
    DeclSeq(Tokenizer toke);
    int parse(Tokenizer t);
    int execute();
    int print();
};


#endif /* declseq_hpp */

