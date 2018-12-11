/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task1 task1.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
    int bRead;
    char b[1];
    while((bRead = read(STDIN_FILENO, b, 1)) > 0){
        write(STDOUT_FILENO, b, bRead);
    }
    return 0;
}
