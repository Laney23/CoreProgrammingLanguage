//
//  idlist.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef idlist_hpp
#define idlist_hpp


#include <sstream>
#include "parse.hpp"
#include "id.hpp"


class IdList : ParseObject {
    int option;
    Id *id;
    IdList *iList;
    
public:
    IdList() : option(0), id(new Id()) {};
    ~IdList() { delete id; if(option == 1) delete iList; }
    int parse(Tokenizer *t);
    int execute();
    int print();
    std::string getIdNames();
    int setId(int value);
};


#endif /* idlist_hpp */
