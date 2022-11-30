#include "parse.cpp"
#include <stdlib.h>
#include <stdio.h>
#include "lex.hpp"
#include "lex.cpp"
#include <string.h>
#include <iostream>


//compile: g++ main.cpp -luser32 -o gopc
//comp.exe compile t.gop

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
          
    
        
            const char * in = lexer::read(argv[2]);
          
          // puts(vec1[1]);
           //makes and allocates token buffer based of length of file * size of token struct
            lexer::lexstream<100> l;
            //gets tokens
            auto out = lexer::matchCTokens<100, 100>(in, l, FSTART);
            int i = 0;
            //test to print tokens
          t_print((*out)[7]);
         
           //frees all allocated buffers
            
        }
    
    else puts("input or parameters invalid\n"
    "Syntax for gopc:\n gopc --compile [filename].gop");
    }
     else puts("input or parameters invalid\n"
    "Syntax for gopc:\n gopc --compile [filename].gop");
}