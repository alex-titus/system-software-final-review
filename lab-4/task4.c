/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task4 task4.c

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
    umask(0);
    struct stat sb;
    stat(argv[2], &sb);
    int size = strlen(argv[2]);
    if(S_ISDIR(sb.st_mode))
    {
        printf("%s Exists as a directory, moving file inside of directory\n", argv[2]);
        sprintf(argv[2]+size, "/%s", argv[1]);
        link(argv[1], argv[2]);
        unlink(argv[1]);
    }
    else
    {
        printf("%s Does not exist as a directory, creating directory and moving file\n", argv[2]);
        mkdir(argv[2], 0700);
        sprintf(argv[2]+size, "/%s", argv[1]);
        link(argv[1], argv[2]);
        unlink(argv[1]);
    }
}
