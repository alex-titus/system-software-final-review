/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task1 task1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

static int alarmFired = 0;
void ding(int sig);

int main(int arc, char **argv)
{
    pid_t pid;
    struct sigaction act;
    act.sa_handler = ding;

    printf("Alarm starting\n");

    pid = fork();
    if(pid == 0)
    {
        sleep(5);
        kill(getppid(), SIGALRM);
        exit(0);
    }
    else
    {
        printf("Waiting for alarm to go off... \n");
        sigaction(SIGALRM, &act, NULL);
        pause();

        if (alarmFired == 1)
        {
            printf("Ding!\n");
        }
        printf("done\n");
        exit(0);
    }
}

void ding(int sig)
{
    alarmFired = 1;
}
