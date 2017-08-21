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


class ParseObject {
protected:
    static bool inDecSeq;
    static int indent;

public:
    ParseObject();
    ~ParseObject() {};
    virtual int parse(Tokenizer *toke) { return SUCCESS; };
    virtual int execute() { return SUCCESS; };
    virtual int print() { return SUCCESS; };
    int printTable();
    int inTable(std::string key);
};


#endif /* parse_hpp */
