#pragma once

#include "lex.hpp"
 #include <cstdlib>
 #include <cstring>
 #include <cstdio>
 #include <cstdbool>
 #include <vector>
 #include <array>

namespace parser{


//makes a dataset of all available members(constants, funcs, vars, literals) in file
template <size_t var_q, size_t const_q>

struct parser_t {
    public:

        std::array<const char *, var_q> variables;
        std::vector<const char *> methods;
        std::array<const char *, const_q> constants;
        const char * entry_main;
        char types[8][10];
        lexer::token end;

        virtual ~parser_t(){}
    };

//struct for prototype ast
template <size_t var_q, size_t const_q> 

struct ASTnode : public parser_t<var_q, const_q>{
    public:
    const char* e_data;

    ASTnode* next;
    ASTnode* back;
    ASTnode* _goto;
    ASTnode* skip;
    ASTnode* loop;   
    
    private:
    ~ASTnode() override{}
};

FILE* newfile = nullptr;

constexpr inline void parse_init();

template <size_t var_q, size_t const_q>     
parser_t<var_q, const_q> 
rec_parse(const char*, const char*);

template <size_t var_q, size_t const_q>     
parser_t<var_q, const_q> 
p_table_gen(parser_t<var_q, const_q> );

template <size_t var_q, size_t const_q> 
bool genCode(parser_t<var_q, const_q> *);
//if successful, return true
//'nuff said 
inline void free_parser();
}