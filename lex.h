#include <stdio.h>
#include <stdlib.h>
//once-overs the header--that way, the compiler doesn't accuse me of redefining things!!
#pragma once
//enumerates types so I can use them in if-statements with the infer macro below
typedef enum {
    _int,
    _char,
    _char_p,
    _bool,
    _float,
    _void_p,
    _token
} types;
//infers type of input and outputs a number that corresponds with enum provided above
#define infer(x) _Generic((x), int:_int, char:_char, \
    char*:_char_p, bool:_bool, token:_token, \
    float:_float, void*:_void_p\
)

#define def(x,y,z) x y = z
//assign int values to tokens 
// -- to be used in switch-statement in lex.c
typedef enum tokens {
    start,
    end,
    arr_open,
    arr_close,
    noToken,
    entry_main, 
    assign,
    method,
    array,
    vector,
    char_,
    str,
    string,
    semi_colon,
    colon,
    comma,
    dot,
    parentheses,
    square_brackets,
    curly_brackets,
    
} token;

//todo: implement \/\/
//custom type for combination of token and string constaant
typedef union{
    token tok;
    const char* str;
} token_str;
//prototype for vector type
typedef void ** vec;

//function declarations for lex.c
const char * read(const char *);
token * matchCTokens(const char*, token*, int);
vec gen_vec(void *);

#ifdef __GNUC__
inline
#endif
void free_read_tokens(token*);

