/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task5 task5.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv){
    umask(0);
    char b[1];
    int bRead;
    int fd1 = open("foo1", O_RDONLY);
    int fd2 = open("foorev", O_CREAT | O_WRONLY, 0760);

    int offset = lseek(fd1, -1, SEEK_END);

    while(offset > 0){
        read(fd1, b, 1);
        write(fd2, b, 1);
        lseek(fd1, -2, SEEK_CUR);
        offset--;
    }

    close(fd1);
    close(fd2);
    return 0;
}
