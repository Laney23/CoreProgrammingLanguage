//
//  cond.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef cond_hpp
#define cond_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "comp.hpp"


class Cond : ParseObject {
    int option;
    Cond c1;
    Cond c2;
    Comp comp;
    
public:
    Cond();
    int parse(Tokenizer t);
    int execute();
    int print();
};




#endif /* cond_hpp */
