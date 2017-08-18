//
//  base.hpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#ifndef base_hpp
#define base_hpp

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <fstream>
#include <sys/stat.h>

#define SUCCESS             0
#define ERROR                 -1

#endif /* base_hpp */

int initMap(std::map<std::string,int>& token_values);
int processFileArgument(const char *file_name, std::ifstream& core_program);
int tearDown(std::ifstream& core_program);
