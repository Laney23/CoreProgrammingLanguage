//
//  assign.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef assign_hpp
#define assign_hpp


#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "exp.hpp"
#include "id.hpp"


class Assign : ParseObject {
    Exp e;
    Id id;
    
public:
    int parse(Tokenizer &t);
    Assign() : e(Exp()), id(Id()) {};
    int execute();
    int print();
};


#endif /* assign_hpp */
