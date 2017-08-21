//
//  id.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef id_hpp
#define id_hpp


#include "parse.hpp"


class Id : ParseObject {
    std::string name;
    int index;
    
public:
    Id() : index(-1) { };
    int parse(Tokenizer *t);
    int execute();
    int print();
    std::string getName();
    int setId(int value);
};


#endif /* id_hpp */
