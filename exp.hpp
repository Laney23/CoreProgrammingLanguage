//
//  exp.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef exp_hpp
#define exp_hpp


#include "parse.hpp"
#include "fact.hpp"


class Fact;

class Exp : ParseObject {
    int option;
    Fact *fact;
    Exp *exp;
    
public:
    Exp();
    ~Exp();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* exp_hpp */
