/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task2 task2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv){
    umask(0);
    char b;
    int bRead;
    int fd1;
    int fd2;
    
    if (access(argv[1], F_OK) != -1){
        printf("File exists");
    } else {
        printf("File doesn't exist");
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY, 0777);

    while((bRead = read(fd1, &b, 1)) > 0){
        write(fd2, &b, bRead);
    }
}
