/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task1 task1.c

    Write your own mv program
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd1 = open("/var/run/utmpp", O_RDONLY);
    if(fd1 <= 0)
    {
        printf("Unable to open utmp file\n");
        exit(1);
    }

    printf("File descriptor value: %d", fd1);
    return 0;
