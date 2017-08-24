//
//  cond.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef cond_hpp
#define cond_hpp


#include "../include/parse.hpp"
#include "../include/comp.hpp"


class Cond : ParseObject {
    int option;
    Cond *c1;
    Cond *c2;
    Comp *comp;
    
public:
    Cond() : option(0) {};
    ~Cond() { if (option == 0) delete comp; else delete c1; if (option == 2 || option == 3) delete c2; }
    int parse(Tokenizer *t);
    int execute();
    int print();
};




#endif /* cond_hpp */
