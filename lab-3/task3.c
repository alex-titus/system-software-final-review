/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task3 task3.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv){
    umask(0);
    char b[32];
    int bRead;
    int fd1 = open("clone2", O_CREAT | O_WRONLY, 0770);
    int fd2 = open("foo", O_RDONLY);

    while((bRead = read(fd2, b, 1)) > 0){
        write(fd1, b, bRead);
    }
    close(fd1);
    close(fd2);
    return 0;
}
