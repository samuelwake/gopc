#pragma once

#include <memory>
#include <cstdio>
#include <cstdlib>
#include <array>
#include <variant>
#include <cstdarg>
#include <iostream>
#include <filesystem>
#include <fstream>
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
    noToken,
    start,
    end,
    d_quote,
    s_quote,
    arr_open,
    arr_close,
    entry_main, 
    assign,
    semi_colon,
    colon,
    comma,
    dot,
    parentheses,
    square_brackets,
    curly_brackets,
    
} token;

struct file_data {
    size_t fsize;
    const char* data;
    file_data(size_t size, const char* fdata): fsize(size), data(fdata)
    {}
};
//todo: implement \/\/
//custom type for combination of token and string constaant
template<std::size_t FSIZE>
using lexstream = std::array<std::variant<const char *, token, char>, FSIZE>;
//prototype for vector type
typedef void ** vec_;

#define vec_push(vector, type, item) { \
    static int vector##count = 0;\
    vector = (vec_)realloc(vector, _msize(vector) + sizeof(type));\
    size_t len = _msize(vector) / sizeof(vector[0]);\
    *(type*)(vector + vector##count ++) = item;\
 }

//function declarations for lex.c
file_data read(const char *);

template<std::size_t size, std::size_t l_size> 
std::unique_ptr<lexstream<size>> 
matchCTokens(const char*, lexstream<l_size>, int);

void get_words(const char*);

template <std::size_t size>
#ifdef __GNUC__
inline
#endif
void free_read_tokens(lexstream<size>*);

}