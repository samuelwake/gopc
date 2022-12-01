#include "lex.hpp"
using namespace lexer;

constexpr int FSTART = 0;

auto t_print = [](const auto& inval){ 
        std::visit( [](const auto &in){
            std::cout<<in;
            }, inval); 
    };

lexer::file_data lexer::read(const char * argv2f){
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
        
        fread(rBuffer, sizeof(char), fsize+1, infile);
        file_data fdata(fsize, static_cast<const char*>(rBuffer));
        fclose(infile);

    return fdata;
}
//hola
//matches individual character tokens to token enum
//recursively adds them to token * list
template<std::size_t size, std::size_t l_size>
std::unique_ptr<lexer::lexstream<size>> 
lexer::matchCTokens(const char * stream, lexstream<l_size> list, int p_inc){
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
        case ']' : list[p_inc] = arr_close; break;
        case '"' : list[p_inc] = d_quote; break;
        case '\'' : list[p_inc] = s_quote; break;
        default : list[p_inc] = stream[p_inc]; break;
    }
    //condition for recursion:
    //when recursion is finished, return the changed token list 
    return static_cast<std::size_t>(p_inc) < len ? 
        lexer::matchCTokens<size,l_size>(stream, list, p_inc+1) : 
        std::make_unique<lexer::lexstream<size>>(list);
}


template <std::size_t size> 
#ifdef __GNUC__
inline
#endif
void free_read_tokens(lexer::lexstream<size>* list) {
    free(list);
}

