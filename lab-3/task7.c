/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task7 task7.c | rm ascii7
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    umask(0);
    int bRead;
    char b[1];

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_CREAT | O_WRONLY, 0777);

    dup2(fd2, 1);
    while((bRead = read(fd1, b, 1)) > 0){
        if (b[0] == 10){
            printf("\n");
        } else if (b[0] == 32){
            printf("");
        } else {
            printf("%d ", b[0]);
        }
    }

    return 0;
}
