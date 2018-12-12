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

void ouch(int sig);

int main(int arc, char **argv)
{
    struct sigaction act;
    act.sa_handler = ouch;

    pid_t pid_a, pid_b;
    pid_a = fork();

    int status;

    if (pid_a == 0)
    {
        sleep(2);
        kill(pid_a, SIGUSR1);
    }
    else
    {
        pid_b = fork();
        if (pid_b == 0){
            sleep(1);
            kill(pid_b, SIGUSR2);
        }
        else
        {
            signal(SIGUSR1, ouch);

            waitpid(pid_b, &status, 0);
        }
        signal(SIGUSR2, ouch);
        waitpid(pid_a, &status, 0);
    }

}

void ouch(int sig)
{
    if (sig = SIGUSR1){
        printf("Hi honey anything wrong\n");
    } else if (sig = SIGUSR2){
        printf("Do you make trouble again\n");
    }
}
