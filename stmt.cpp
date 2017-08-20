//
//  stmt.cpp
//  CoreProgrammingLanguage
//
//  Created by Josh Laney on 8/19/17.
//  Copyright © 2017 Aginor. All rights reserved.
//

#include "stmt.hpp"


//TODO: comment htis
Stmt::~Stmt()
{
    if(Stmt::option == 1)
        delete Stmt::iff;
    if(Stmt::option == 2)
        delete Stmt::loop;
    /*if(option == 3) delete in;*/
    if(Stmt::option == 4)
        delete Stmt::out;
    if(Stmt::option == 5)
        delete Stmt::assign;
}


/*
 * Name: parse
 * Purpose: parse the Stmt object
 * Parameters: Tokenizer t          token object to parse
 * Return: SUCCESS or ERROR
 */
int Stmt::parse(Tokenizer *t)
{
printf("start of statement %d\n", t->front().value);
    /* Check the first token */
    TokenPair p = t->front();
    
    /* Parse each type of statement individually */
    switch (p.value) {
        case 5:        /* if */
            Stmt::iff = new Iff();
            if (Stmt::iff->parse(t) != SUCCESS)
                return ERROR;
            break;
        case 8:       /* while */
            Stmt::option = 1;
            Stmt::loop = new Loop();
            if (Stmt::loop->parse(t) != SUCCESS)
                return ERROR;
            break;
//        case 10:     /* read */
//            Stmt::option = 2;
//            Stmt::in = new Input();
//            if (Stmt::in->parse(t) != SUCCESS)
//                return ERROR;
//            break;
        case 11:     /* write */
            Stmt::option = 3;
            Stmt::out = new Output();
            if (Stmt::out->parse(t) != SUCCESS)
                return ERROR;
            break;
        case 32:     /* identifier */
            Stmt::option = 4;
            Stmt::assign = new Assign();
            if (Stmt::assign->parse(t) != SUCCESS)
                return ERROR;
            break;
            
        default:
            break;      /* Should never happen */
    }
    
printf("end of statement %d\n", t->front().value);
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
    switch (Stmt::option) {
        case 0:
            if (Stmt::iff->execute() != SUCCESS)
                return ERROR;
            break;
        case 1:
            if (Stmt::loop->execute() != SUCCESS)
                return ERROR;
            break;
//        case 2:
//            if (Stmt::in->execute() != SUCCESS)
//                return ERROR;
//            break;
        case 3:
            if (Stmt::out->execute() != SUCCESS)
                return ERROR;
            break;
        case 4:
            if (Stmt::assign->execute() != SUCCESS)
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
    
    return SUCCESS;
} /* function print */



