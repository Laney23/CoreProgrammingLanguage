//
//  base.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "base.hpp"


/*
 * Name: processFileArgument
 *
 * Purpose: Processes and validates the file argument
 *
 * Parameters: 
 *
 * Return: SUCCESS
 */
int processFileArgument(const char *file_name, std::ifstream& core_program)
{
    /* Verify file exists in current directory */
    
    /* Open file for processing */
    core_program.open(file_name, std::ios::in);
    
    return SUCCESS;
} /* function processFileArgument */


/*
 * Name: tearDown
 *
 * Purpose: frees memory before exit
 *
 * Parameters: std::ifstream& core_program      file stream to close
 *
 * Return: SUCCESS
 */
int tearDown(std::ifstream& core_program)
{
    core_program.close();
    
    return SUCCESS;
} /* function tearDown */


/*
 * Name: initMap
 *
 * Purpose: Initializes the token map.
 *
 * Parameters: std::map<char*,int> token_values         map to populate
 *
 * Return: SUCCESS
 */
int initMap(std::map<std::string,int> token_values)
{
    token_values["program"] = 1;
    token_values["begin"] = 2;
    token_values["end"] = 3;
    token_values["int"] = 4;
    token_values["if"] = 5;
    token_values["then"] = 6;
    token_values["else"] = 7;
    token_values["while"] = 8;
    token_values["loop"] = 9;
    token_values["read"] = 10;
    token_values["write"] = 11;
    token_values[";"] = 12;
    token_values[","] = 13;
    token_values["="] = 14;
    token_values["!"] = 15;
    token_values["["] = 16;
    token_values["]"] = 17;
    token_values["&&"] = 18;
    token_values["||"] = 19;
    token_values["("] = 20;
    token_values[")"] = 21;
    token_values["+"] = 22;
    token_values["-"] = 23;
    token_values["*"] = 24;
    token_values["!="] = 25;
    token_values["=="] = 26;
    token_values["<"] = 27;
    token_values[">"] = 28;
    token_values["<="] = 29;
    token_values[">="] = 30;
    token_values["NUMBER"] = 31;
    token_values["IDENTIFIER"] = 32;
    token_values["EOF"] = 33;
    
    return SUCCESS;
} /* function initMap */





