#pragma once

#include "lex.hpp"
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdbool.h>
namespace parser{
     
struct p {
        const char * variables;
        const char * methods;
        const char * constants;
        const char * entry_main;
        char types[8][10];
        token end;
    } * parse;
typedef struct p parser;

FILE* newfile;

parser* par;
parser* parse_init();
parser rec_parse(const char*, const char*);
parser p_table_gen(parser);

__attribute__((const)) bool genCode(parser *);
//if successful, return true
//'nuff said 
inline void free_parser();
}