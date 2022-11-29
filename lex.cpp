#include "lex.hpp"
#include <cstdarg>

namespace lexer{

const char * read(const char * argv2f){
    //reads input file
    token_str t;
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
vec_ gen_vec(types * _types, int items,  ...){
    vec_ newvec = (vec_)malloc(sizeof(char*));
    va_list args;
    va_start(args, items);
    
    for(int count = 0; (sizeof(_types) / sizeof(_types[0])) + 1 > count; count++) 
    {   
       /* if(count == 0) 
        {
            newvec = (vec_)malloc(items*sizeof(char*));
            *()newvec;
            count++;
        }*/

        switch(_types[count]){
            case _int: 
            vec_push(newvec, int, va_arg(args, int));
            break;
            case _char_p: 
            vec_push(newvec, char*, va_arg(args, char*));
            break;
            //case _token: 
            //vec_push(newvec, token, va_arg(args, token));
           // break;
            default:
           va_end(args); 
            return newvec;
        }
    }
    va_end(args);
    return newvec;
}
//matches individual character tokens to token enum
//recursively adds them to token * list
token* matchCTokens(const char * stream, token * list, int p_inc){
    //get array size for string constant stream
     size_t len = sizeof(stream) / sizeof(stream[0]);
    //assignment for list
    switch(stream[p_inc]){
        case ' ' : *(list+p_inc) = noToken; break;
        case ';' : *(list+p_inc) = semi_colon; break;
        case ':' : *(list+p_inc) = colon; break;
        case ',' : *(list+p_inc) = comma; break;
        case '.' : *(list+p_inc) = dot; break;
        case '=' : *(list+p_inc) = assign; break;
        case '{' : *(list+p_inc) = start; break;
        case '}' : *(list+p_inc) = end; break;
        case '[' : *(list+p_inc) = arr_open; break;
        case ']' : *(list+p_inc) = arr_open; break;
        default : *(list+p_inc) = end; break;
    }
    //condition for recursion:
    //when recursion is finished, return the changed token list 
    return (size_t)p_inc < len ? matchCTokens(stream, list, p_inc+1) : list;
}


#ifdef __GNUC__
inline
#endif 
void free_read_tokens(token * list) {
    free(list);
}

#ifdef __GNUC__
inline
#endif 
void destroy_vec(vec_ vector) {
    free(vector);
}
}