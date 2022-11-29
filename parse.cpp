#include "parse.hpp"
//inlining function if GNUC compiler (g++, gcc) is found
//basically puts simple functions in same embedded bloc
//only a suggestion to the compiler, tho. It's smarter than me

//init the parser 
//sets size, var names, then copies to array values
parser* parse_init(){
    size_t psize = (sizeof(parser) + 1);
    //declaring struct members
    const char * type_arr[8] = {"int", "float", 
    "bool", "char", "&str", 
    "string", "[]"};
    //allocates memory for parser (+1 byte for just to be safe)
   par = (parser*)calloc(1, psize+1);
    //assigns members
    par->constants = "const";
   par->variables = "let";
   par->end = end;
   par->entry_main = "main";
   par->methods = "fn";

    //copies strings into each type member
    //uses strncopy for memory safety
    strncpy(par->types[0], type_arr[0], 10);
    strncpy(par->types[1], type_arr[1], 10);
    strncpy(par->types[2], type_arr[2], 10);
    strncpy(par->types[3], type_arr[3], 10);
    strncpy(par->types[4], type_arr[4], 10);
    strncpy(par->types[5], type_arr[5], 10);
    strncpy(par->types[6], type_arr[6], 10);
    //returns pointer to parser
  return par;
}

#ifdef __GNUC__
inline
#endif
//destroys parser
extern void free_parser(){
    free(par);
}
