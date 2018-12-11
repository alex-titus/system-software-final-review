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

int hasPalin(int fd1, int fd2);

int main(int argc, char **argv){
    umask(0);
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = dup(fd1);

    int result = hasPalin(fd1, fd2);

    if(result == 1){
        printf("Has a palindrome\n");
    } else {
        printf("Does not have a palindrome\n");
    }
    close(fd1);
    close(fd2);
    return 0;
}

int hasPalin(int fd1, int fd2){
    char a, b;
    int i;
    int offset = lseek(fd1, -1, SEEK_END)+1;

    for(i = 0; i < offset-1; i++){
        lseek(fd1, i, SEEK_SET);
        read(fd1, &a, 1);

        lseek(fd2, (-2-i), SEEK_END);
        read(fd2, &b, 1);

        if(a != b){
            return 0;
        }
    }
    return 1;
}
