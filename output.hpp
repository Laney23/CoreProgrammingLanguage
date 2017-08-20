//
//  output.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef output_hpp
#define output_hpp


#include <stdio.h>
#include <vector>
#include "parse.hpp"
#include "tokenizer.hpp"
#include "idlist.hpp"


class Output : ParseObject {
    IdList iList;
    
public:
    int parse(Tokenizer &t);
    Output() : iList(IdList()) { };
    int execute();
    int print();
};


#endif /* output_hpp */
