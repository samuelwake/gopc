#include "parse.cpp"
#include <stdlib.h>
#include <stdio.h>
#include "lex.hpp"
#include "lex.cpp"
#include <string.h>

//compile: g++ main.c -luser32 -o gopc
//comp.exe compile t.gop

// \/ \/ \/ driver code \/ \/ \/
int main(int argc, const char ** argv){
    token * t;
    //checks if argc is at least 2
    //this is to prevent a buffer overflow / segfault 
    //because the compiler doesn't like empty strings
    if(argc>=2){
        const char * ext = strrchr(argv[2], '.');
        //case-insensitive check for --compile parameter and correct file extension
        if(stricmp(argv[1], "--compile") == 0 && strncmp(ext, ".gop", 5) == 0){
            //reads file
            types vtypes[] = {_int, _char_p};
           vec_ vec1 = gen_vec( vtypes, 3, 2, "hullo!");
           printf("%d", vec1[0]);
            const char * in  = read(argv[2]);
            parse_init();
          // puts(vec1[1]);
           //makes and allocates token buffer based of length of file * size of token struct
            t = (token*)calloc(sizeof(token),strlen(in));
            //gets tokens
            matchCTokens(in, t, 0);
            int i = 0;
            //test to print tokens
            while(i<sizeof(t)-1){
            printf("%d ", t[i]);
            i++;
            }
           //frees all allocated buffers
            free_parser();
            free((void*)in);
            free(t);
        }
    
    else puts("input or parameters invalid\n"
    "Syntax for gopc:\n gopc --compile [filename].gop");
    }
     else puts("input or parameters invalid\n"
    "Syntax for gopc:\n gopc --compile [filename].gop");
}