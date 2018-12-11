/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task4 task4.c
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
    int fd2 = open("foo2", O_RDONLY);
    int fd3 = open("foo12", O_CREAT | O_WRONLY, 0760);

    while((bRead = read(fd1, b, 1)) > 0){
        write(fd3, b, bRead);
    }

    lseek(fd3, SEEK_END, -1);
    
    while((bRead = read(fd2, b, 1)) > 0){
        write(fd3, b, bRead);
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
