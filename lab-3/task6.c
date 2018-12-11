/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task6 task6.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int simpleAtoI(char *string);

int main(int argc, char **argv){
    int total = 0;
    int j = 1;

    if(argc <= 1){
        printf("Please pass integer values on command line\n");
        exit(1);
    }

    for(j; j < argc; j++){
        printf("adding value:%d\n", simpleAtoI(argv[j]));
        int value = simpleAtoI(argv[j]);
        total+=value;
    }

    printf("Total value: %d\n", total);
    return 0;
}

int simpleAtoI(char *string){
    int result = 0;
    int i = 0;
    for (i; string[i] != '\0'; i++){
        result = result*10 + string[i] - '0';
    }
    return result;
}
