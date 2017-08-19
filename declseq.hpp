//
//  declseq.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef declseq_hpp
#define declseq_hpp


#include <stdio.h>
#include <string>
#include "parse.hpp"
#include "tokenizer.hpp"


class DeclSeq {
    int option;
    Decl decl;
    DeclSeq declSeq;
    
public:
    DeclSeq(Tokenizer toke);
    int parse(Tokenizer t);
    int execute();
    int print();
};


#endif /* declseq_hpp */




class DeclSeq:		# DONE
def execute(self):
self.decl.execute()
if self.option == 1:
self.declSeq.execute()

def Print(self):
self.decl.Print()
if self.option == 1:
self.declSeq.Print()

