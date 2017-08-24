//
//  stmt.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "../include/stmt.hpp"

using namespace std;


/*
 * Name: Stmt destructor
 * Purpose: destroy the Stmt object
 */
Stmt::~Stmt()
{
    if(option == 1)
        delete iff;
    if(option == 2)
        delete loop;
    /*if(option == 3) delete in;*/
    if(option == 4)
        delete out;
    if(option == 5)
        delete assign;
} /* function Stmt destructor */


/*
 * Name: parse
 * Purpose: parse the Stmt object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Stmt::parse(Tokenizer *t)
{
    /* Check the first token */
    TokenPair p = t->front();
    
    /* Parse each type of statement individually */
    switch (p.value) {
        case 5:        /* if */
            iff = new Iff;
            if (iff->parse(t) != SUCCESS)
                return ERROR;
            break;
        case 8:       /* while */
            option = 1;
            loop = new Loop();
            if (loop->parse(t) != SUCCESS)
                return ERROR;
            break;
//        case 10:     /* read */
//            option = 2;
//            in = new Input();
//            if (in->parse(t) != SUCCESS)
//                return ERROR;
//            break;
        case 11:     /* write */
            option = 3;
            out = new Output();
            if (out->parse(t) != SUCCESS)
                return ERROR;
            break;
        case 32:     /* identifier */
            option = 4;
            assign = new Assign();
            if (assign->parse(t) != SUCCESS)
                return ERROR;
            break;
            
        default:
            break;      /* Should never happen */
    }
    
    return SUCCESS;
} /* function parse */


/*
 * Name: execute
 * Purpose: execute the Stmt object
 * Return: SUCCESS or ERROR
 */
int Stmt::execute()
{
    /* Execute the proper statement */
    switch (option) {
        case 0:
            if (iff->execute() != SUCCESS)
                return ERROR;
            break;
        case 1:
            if (loop->execute() != SUCCESS)
                return ERROR;
            break;
//        case 2:
//            if (in->execute() != SUCCESS)
//                return ERROR;
//            break;
        case 3:
            if (out->execute() != SUCCESS)
                return ERROR;
            break;
        case 4:
            if (assign->execute() != SUCCESS)
                return ERROR;
            break;
            
        default:            /* This will never happen */
            break;
    }
    
    return SUCCESS;
} /* function execute */


/*
 * Name: print
 * Purpose: print the Stmt object
 * Return: SUCCESS or ERROR
 */
int Stmt::print()
{
    /* Increase tab */
    indent++;
    
    /* Execute the proper statement */
    switch (option) {
        case 0:
            if (iff->print() != SUCCESS)
                return ERROR;
            break;
        case 1:
            if (loop->print() != SUCCESS)
                return ERROR;
            break;
            //        case 2:
            //            if (in->print() != SUCCESS)
            //                return ERROR;
            //            break;
        case 3:
            if (out->print() != SUCCESS)
                return ERROR;
            break;
        case 4:
            if (assign->print() != SUCCESS)
                return ERROR;
            break;
            
        default:            /* This will never happen */
            break;
    }
    
    /* Reduce indent */
    indent--;
    
    return SUCCESS;
} /* function print */



