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
#include <iostream>
#include "../include/tokenizer.hpp"
#include "../include/table.hpp"


class ParseObject {
protected:
    static bool inDecSeq;
    static int indent;

public:
    ParseObject() { idTable = IdTable::instance(); inDecSeq = true; indent = 0; };
    virtual ~ParseObject() {};
    IdTable *idTable;
    virtual int parse(Tokenizer *toke) { return SUCCESS; };
    virtual int execute() { return SUCCESS; };
    virtual int print() { return SUCCESS; };
};


#endif /* parse_hpp */
