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
#include <string.h>

int main(int argc, char **argv){
    umask(0);
    char home[256];
    char target[256];

    sprintf(home, "%s", getenv("HOME"));
    sprintf(target, "%s", getenv("HOME"));
    int x = strlen(home);

    sprintf(home+x, "%s", "/Dir1");
    mkdir(home, 0700);
    sprintf(home+x, "%s", "/Dir2");
    mkdir(home, 0700);
    sprintf(home+x, "%s", "/Dir2/Dir12");
    mkdir(home, 0700);

    char b;
    int bRead;

    strcat(home, "/hello");
    int fd1 = open("hello", O_RDONLY);
    int fd2 = open(home, O_CREAT | O_WRONLY, 0777);
    while((bRead = read(fd1, &b, 1)) > 0){
        write(fd2, &b, bRead);
    }

    sprintf(home+x, "%s", "/Dir1/toDir12");
    sprintf(target+x, "%s", "/Dir2/Dir12");
    symlink(home, target);

    sprintf(home+x, "%s", "/Dir1/toHello");
    sprintf(target+x, "%s", "/Dir2/Dir12/hello");
    symlink(home, target);
}
