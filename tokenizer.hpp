/*
*  tokenizer.hpp
*  CoreProgrammingLanguage
*
*  Created by Josh Laney on 8/17/17.
*  Copyright © 2017 Aginor. All rights reserved.
*/

#ifndef tokenizer_hpp
#define tokenizer_hpp


#include <stdio.h>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <sys/stat.h>
#include <vector>
#include "base.hpp"


#define DELIMS_             " \f\n\r\t\v"
#define PROGRAM         1
#define BEGIN                2
#define END                   3
#define INT                     4
#define IF                        5
#define THEN                 6
#define ELSE                   7
#define WHILE                8
#define LOOP                 9
#define READ                 10
#define WRITE                11
#define SEMIC                12
#define COMMA            13
#define EQUAL               14
#define LP                       20
#define RP                       21
#define PLUS                   22
#define MINUS                23
#define TIMES                 24
#define NUMBER            31
#define IDENTIFIER        32


struct TokenPair
{
    int value;
    std::string token;
};


class Tokenizer {
    std::vector<TokenPair> tokens;
    std::map<std::string,int> token_lookup_table;
    std::ifstream core_program;
    int cursor;
    
public:
    Tokenizer(std::string file_name);
    int tokenize();
    int processFileArgument(std::string file_name);
    void print();
    TokenPair getToken();
    TokenPair skipToken();
    int intVal();
    std::string idName();
    int totalTokens();
    TokenPair front();
    
protected:
    int tokenizeLine(const std::string& str);
};


#endif /* tokenizer_hpp */
