//
//  output.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/20/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef output_hpp
#define output_hpp


#include <vector>
#include "../include/parse.hpp"
#include "../include/idlist.hpp"

class Output : ParseObject {
    IdList *iList;
    
public:
    Output() { };
    ~Output();
    int parse(Tokenizer *t);
    int execute();
    int print();
};


#endif /* output_hpp */
