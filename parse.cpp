#include "parse.hpp"
//inlining function if GNUC compiler (g++, gcc) is found
//basically puts simple functions in same embedded bloc
//only a suggestion to the compiler, tho. It's smarter than me
using namespace parser;
//init the parser 
//sets size, var names, then copies to array values
constexpr inline void parse_init(){}