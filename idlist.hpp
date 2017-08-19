//
//  idlist.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef idlist_hpp
#define idlist_hpp

#include <stdio.h>
#include "parse.hpp"
#include "tokenizer.hpp"


class IdList {
    Id id;
    IdList iList;
    int option;
    
public:
    IdList(Tokenizer toke);
    int parse(Tokenizer t);
    int execute();
    int print();
    void setId(int value);
};


#endif /* idlist_hpp */
