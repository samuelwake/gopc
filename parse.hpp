#pragma once

#include "lex.hpp"
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdbool.h>
namespace parser{
     
struct p {
    public:
        const char * variables;
        const char * methods;
        const char * constants;
        const char * entry_main;
        char types[8][10];
        lexer::token end;
    };
typedef struct p parser_t;

FILE* newfile = nullptr;

parser_t* par;
parser_t* parse_init();
parser_t rec_parse(const char*, const char*);
parser_t p_table_gen(parser_t);

__attribute__((const)) bool genCode(parser_t *);
//if successful, return true
//'nuff said 
inline void free_parser();
}