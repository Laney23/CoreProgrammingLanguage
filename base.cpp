//
//  base.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/17/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "base.hpp"


/*
 * Name: initMap
 *
 * Purpose: Initializes the token map.
 *
 * Parameters: std::map<char*,int> token_values         map to populate
 *
 * Return: SUCCESS
 */
int initMap(std::map<char*,int> token_values)
{
    token_values[(char*)"program"] = 1;
    token_values[(char*)"begin"] = 2;
    token_values[(char*)"end"] = 3;
    token_values[(char*)"int"] = 4;
    token_values[(char*)"if"] = 5;
    token_values[(char*)"then"] = 6;
    token_values[(char*)"else"] = 7;
    token_values[(char*)"while"] = 8;
    token_values[(char*)"loop"] = 9;
    token_values[(char*)"read"] = 10;
    token_values[(char*)"write"] = 11;
    token_values[(char*)";"] = 12;
    token_values[(char*)","] = 13;
    token_values[(char*)"="] = 14;
    token_values[(char*)"!"] = 15;
    token_values[(char*)"["] = 16;
    token_values[(char*)"]"] = 17;
    token_values[(char*)"&&"] = 18;
    token_values[(char*)"||"] = 19;
    token_values[(char*)"("] = 20;
    token_values[(char*)")"] = 21;
    token_values[(char*)"+"] = 22;
    token_values[(char*)"-"] = 23;
    token_values[(char*)"*"] = 24;
    token_values[(char*)"!="] = 25;
    token_values[(char*)"=="] = 26;
    token_values[(char*)"<"] = 27;
    token_values[(char*)">"] = 28;
    token_values[(char*)"<="] = 29;
    token_values[(char*)">="] = 30;
    token_values[(char*)"NUMBER"] = 31;
    token_values[(char*)"IDENTIFIER"] = 32;
    token_values[(char*)"EOF"] = 33;
    
    return SUCCESS;
} /* function initMap */





