#include "lex.hpp"
#include <cstdarg>

using namespace lexer;

 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA 
constexpr int FSTART = 0;

const char * lexer::read(const char * argv2f){
    //reads input file
    
    //opens src file
    FILE* infile = fopen(argv2f, "r");
        //gets file size from beginning to end
        fseek(infile, 0, SEEK_END);
        size_t fsize = (size_t)ftell(infile);
        fseek(infile, 0, SEEK_SET);
        //allocating string / char* buffer 
        //to be used for reading the input file
        char * rBuffer = (char*)calloc(1, fsize+3);
        fread(rBuffer, sizeof(char), fsize+3, infile);
        fclose(infile);

    return (const char*)rBuffer;
}
//hola
//matches individual character tokens to token enum
//recursively adds them to token * list
template<std::size_t size, std::size_t l_size>
lexer::lexstream<size> lexer::matchCTokens(const char * stream, lexstream<l_size>&& list, int p_inc){
    //get array size for string constant stream
     //dummy

    auto len = list.max_size();
    //assignment for list
    switch(stream[p_inc]){
        case ' ' : list[p_inc]  = noToken; break;
        case ';' : list[p_inc] = semi_colon; break;
        case ':' : list[p_inc] = colon; break;
        case ',' : list[p_inc] = comma; break;
        case '.' : list[p_inc] = dot; break;
        case '=' : list[p_inc] = assign; break;
        case '{' : list[p_inc] = start; break;
        case '}' : list[p_inc] = end; break;
        case '[' : list[p_inc] = arr_open; break;
        case ']' : list[p_inc] = arr_open; break;
        default : list[p_inc] = end; break;
    }
    //condition for recursion:
    //when recursion is finished, return the changed token list 
    return static_cast<std::size_t>(p_inc) < len ? lexer::matchCTokens<100,100>(stream, std::move(list), p_inc+1) : list;
}


#ifdef __GNUC__
inline
#endif 
void free_read_tokens(token * list) {
    free(list);
}

