//
//  assign.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef assign_hpp
#define assign_hpp


#include "../include/parse.hpp"
#include "../include/exp.hpp"
#include "../include/id.hpp"


class Assign : ParseObject {
    Exp *e;
    Id *id;
    
public:
    Assign() : e(new Exp()), id(new Id()) {};
    ~Assign() { delete e; delete id; }
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* assign_hpp */
