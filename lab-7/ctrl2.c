/*  This softwar/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o ctrl1 ctrl1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void ouch(int sig);

int main(int arc, char **argv)
{
    struct sigaction act;
    act.sa_handler = ouch;

    //(void) signal(SIGINT, ouch);
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGQUIT, &act, NULL);

    while (1)
    {
        printf("Hello World!\n");
        sleep(1);
    }
}

void ouch(int sig)
{
    printf("I got signal %d\n", sig);
    (void) signal(SIGINT, SIG_DFL);
    (void) signal(SIGQUIT, SIG_DFL);
}
