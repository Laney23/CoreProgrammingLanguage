//
//  parse.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef parse_hpp
#define parse_hpp

#include <stdio.h>
#include "tokenizer.hpp"

class ParseObject {
   
public:
    virtual int parse(Tokenizer::Tokenizer toke);
    virtual int execute();
    virtual int print();
};


#endif /* parse_hpp */
