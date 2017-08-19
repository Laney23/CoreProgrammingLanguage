//
//  id.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef id_hpp
#define id_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"


class Id : ParseObject {
    std::string name;
    
public:
    Id(Tokenizer toke);
    int parse(Tokenizer t);
    int execute();
    int print();
    void setId(int value);
};


#endif /* id_hpp */