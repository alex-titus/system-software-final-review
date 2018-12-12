/*  This softwar/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task3 task3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigHandler(int sig){
	signal(SIGQUIT, SIG_DFL);
	printf("OUCH! - I got signal %d\n", sig);
}



int main(int arc, char **argv)
{
    sigset_t set1, set2;

    sigemptyset(&set1);
    sigaddset(&set1, SIGQUIT);
    sigaddset(&set1, SIGINT);
    sigprocmask(SIG_BLOCK, &set1, NULL);
    int i;
    printf("Blocking SIGINT, SIGQUIT\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    signal(SIGINT, sigHandler);
    signal(SIGQUIT, sigHandler);
    sigprocmask(SIG_UNBLOCK, &set1, NULL);

    sigemptyset(&set2);
    sigaddset(&set2, SIGINT);
    sigprocmask(SIG_BLOCK, &set2, NULL);
    int j;
    printf("Blocking SIGINT\n");
    for(j = 0; j < 5; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }
}
