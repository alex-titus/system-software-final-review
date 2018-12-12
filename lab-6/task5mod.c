/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task5mod task5mod.c | rm childMod.txt | rm parentMod.txt

    parent contains a copy of it, while child only has digits
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int isDigit(char c);

int main(int arc, char **argv)
{
    int offset1, offset2;
    int fd1 = open(argv[1], O_RDONLY);
    int size = lseek(fd1, -1, SEEK_END);
    lseek(fd1, 0, SEEK_CUR);

    int fdP = open("parentMod.txt", O_CREAT | O_RDONLY, 0666);
    int fdC = open("childMod.txt", O_CREAT | O_RDONLY, 0666);

    pid_t pid;
    pid = fork();

    char b;

    while((offset1 <= size) && (offset2 <= size))
    {
        if (pid == 0)
        {
            lseek(fd1, offset1, SEEK_SET);
            read(fd1, &b, 1);
            if(isDigit(b) == 1)
            {
                write(fdC, &b, 1);
            }
            offset2++;
        }
        else
        {
            lseek(fd1, offset2, SEEK_SET);
            read(fd1, &b, 1);
            write(fdP, &b, 1);
            offset2++;
        }
    }
    close(fd1);
    close(fdP);
    close(fdC);
}

int isDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
