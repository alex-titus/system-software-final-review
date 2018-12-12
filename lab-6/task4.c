/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task4 task4.c

    fork with exec
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int arc, char **argv)
{
    int Np, Tp, status;
    Np = atoi(argv[2]);
    Tp = atoi(argv[4]);

    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        execl("child", argv[1], argv[3], "Hello from the parent",  (char *)NULL);
    }
    else
    {
        wait(&status);
        int j;
        for (j = 0; j < Np; j++)
        {
            printf("Parent Process - pid: %d\n", getpid());
            sleep(Tp);
        }
    }
}
