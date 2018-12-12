/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o child child.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int arc, char **argv)
{
    int Nc, Tc;
    Nc = atoi(argv[1]);
    Tc = atoi(argv[2]);
    int i = 0;
    for (i = 0; i < Nc; i++)
    {
        printf("Child process - pid: %d, message: %s\n", getpid(), argv[3]);
        sleep(Tc);
    }
    return 37;
}
