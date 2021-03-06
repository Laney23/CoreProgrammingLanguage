//
//  compop.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef compop_hpp
#define compop_hpp


#include "../include/parse.hpp"


class CompOp : ParseObject {
    int option;
    
public:
    CompOp() : option(0) {};
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* compop_hpp */
