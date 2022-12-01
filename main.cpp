#include "parse.cpp"
#include <stdlib.h>
#include <stdio.h>
#include "lex.hpp"
#include "lex.cpp"
#include <string.h>
#include <iostream>


//compile: g++ main.cpp -luser32 -o gopc
//gopc compile t.gop
//combined: g++ main.cpp -luser32 -o gopc && ./gopc --compile t.gop

// \/ \/ \/ driver code \/ \/ \/
int main(int argc, const char ** argv){
    //checks if argc is at least 2
    //this is to prevent a buffer overflow / segfault 
    //because the compiler doesn't like empty strings
    if(argc>=2){
        const char * ext = strrchr(argv[2], '.');
        //case-insensitive check for --compile parameter and correct file extension
        if(stricmp(argv[1], "--compile") == 0 && strncmp(ext, ".gop", 5) == 0){
            //reads file
            lexer::file_data in = lexer::read(argv[2]);
            const size_t size = in.fsize;
            lexer::lexstream<100> l;
            //gets tokens
            
            auto out = lexer::matchCTokens<100, 100>(in.data, l, FSTART);
            //test to print tokens
            for (int i = 0; i<out->size()-1; i++)
          t_print((*out)[i]);
         
           //frees all allocated buffers
            
        }
    
    else puts("input or parameters invalid\n"
    "Syntax for gopc:\n gopc --compile [filename].gop");
    }
     else puts("input or parameters invalid\n"
    "Syntax for gopc:\n gopc --compile [filename].gop");
}