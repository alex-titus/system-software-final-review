/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task3 task3.c

    Create new processes using fork, parent waits for child
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int arc, char **argv)
{
    int Nc, Np, Tc, Tp, status;
    Nc = atoi(argv[1]);
    Np = atoi(argv[2]);
    Tc = atoi(argv[3]);
    Tp = atoi(argv[4]);

    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        int i;
        for (i = 0; i < Nc; i++)
        {
            printf("This is the child\n");
            sleep(Tc);
        }
    }
    else
    {
        wait(&status);
        int j;
        for (j = 0; j < Np; j++)
        {
            printf("This is the parent\n");
            sleep(Tp);
        }
    }
}
