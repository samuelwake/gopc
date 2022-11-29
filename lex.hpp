#pragma once
#include <cstdio>
#include <cstdlib>
#include <array>
#include <variant>
//once-overs the header--that way, the compiler doesn't accuse me of redefining things!!
namespace lexer {
//enumerates types so I can use them in if-statements with the infer macro below
typedef enum {
    _int,
    _char,
    _char_p,
    _bool,
    _float,
    _void_p,
    d_void_p,
    _token
} types;
//infers type of input and outputs a number that corresponds with enum provided above
#define infer(x) _Generic((x), \
    int:_int, char:_char, \
    char*:_char_p, bool:_bool, \
    token:_token, float:_float, \
    void*:_void_p, void**:d_void_p \
)

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
std::array<std::variant<>>
//prototype for vector type
typedef void ** vec_;

#define vec_push(vector, type, item) { \
    static int vector##count = 0;\
    vector = (vec_)realloc(vector, _msize(vector) + sizeof(type));\
    size_t len = _msize(vector) / sizeof(vector[0]);\
    *(type*)(vector + vector##count ++) = item;\
 }

//function declarations for lex.c
const char * read(const char *);
token * matchCTokens(const char*, token*, int);
void get_words(const char*);
vec_ gen_vec(types[], int,  ...);

#ifdef __GNUC__
inline
#endif
void free_read_tokens(token*);

}