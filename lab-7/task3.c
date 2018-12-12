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

int main(int arc, char **argv)
{
    pid_t pid;
    pid = fork();
    int fd1 = open("message.txt", O_CREAT | O_WRONLY);

    int status;
    char message[7] = "Hi, Mom";
    if (pid == 0)
    {
        write(fd1, message, 7);
        exit(0);
    }
    else
    {
        int bRead;
        char *b;
        wait(&status);
        lseek(fd1, 0, SEEK_SET);
        printf("My child said ");
        while((bRead = read(fd1, &b, 1)) > 0)
        {
            write(1, &b, bRead);
        }
    }
    close(fd1);
}
