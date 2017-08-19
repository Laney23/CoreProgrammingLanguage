//
//  exp.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef exp_hpp
#define exp_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "fact.hpp"


class Exp : ParseObject {
    int option;
    Fact fact;
    Exp exp;
    
public:
    Exp();
    int parse(Tokenizer t);
    int execute();
    int print();
};


#endif /* exp_hpp */
