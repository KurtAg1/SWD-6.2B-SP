#ifndef LO1_H
#define LO1_H

#include <stdio.h>
#include <stdbool.h>

/* returns true if –c is passed as the first command line argument */ 
bool should_count_chars(int argc, char* argv[]){
    if (argc > 1)
    {
        // check for flag
        return (argv[1][0] == '-' && argv[1][1] == 'c');
    }
    return false;
}

/* returns true if the character passed is a space or a tab */ 
bool is_space(char c){
    return c == ' ' || c == '\t';
}

#endif