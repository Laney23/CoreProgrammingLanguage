//
//  decl.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef decl_hpp
#define decl_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"


class Decl {
    IdList iList;
    
public:
    Decl(Tokenizer toke);
    int parse(Tokenizer t);
    int execute();
    int print();
};


#endif /* decl_hpp */
