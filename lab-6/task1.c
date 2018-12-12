/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task1 task1.c
*/

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
    char **b = environ;
    printf("%s\n", *b);
}
