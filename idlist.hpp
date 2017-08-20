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
#include "id.hpp"


class IdList : ParseObject {
    int option;
    Id id;
    IdList iList;
    
public:
    IdList() : option(0), id(Id()) {};
    int parse(Tokenizer *t);
    int execute();
    int print();
    std::string getIdNames();
    int setId(int value);
};


#endif /* idlist_hpp */
