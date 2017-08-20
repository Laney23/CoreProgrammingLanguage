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
#include <vector>
#include "tokenizer.hpp"


struct TableElement {
    std::string idName;
    int idVal;
    bool isInit;
};


class ParseObject {
protected:
    bool inDecSeq;
    int indent;
    std::vector<TableElement> idTable;

public:
    virtual int parse(Tokenizer *toke);
    virtual int execute();
    virtual int print();
    int inTable(std::string key);
};


#endif /* parse_hpp */
