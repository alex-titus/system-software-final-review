/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task1 task1.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int convIntToStr(char *str, int x);
int convStrToInt(char *str);
int isDigit(int c);

int main(int argc, char **argv){
    int bRead;
    int i = 0;
    char b;
    char string[80];
    int fd1 = open(argv[1], O_RDONLY);
    while((bRead = read(fd1, &b, 1)) > 0){
        if(isDigit(b) >= 1){
            string[i] = b;
            i++;
        }
    }
    printf("String from file is: %s\n", string);
    int intFromFile = convStrToInt(string);
    printf("Int from file is: %d\n", intFromFile);
    intFromFile+=10;
    printf("Int+10 from file is: %d\n", intFromFile);
    char newString[80];
    convIntToStr(newString, intFromFile);
    printf("String+10 from file is: %s\n", newString);
}

int convIntToStr(char *str, int x){
    sprintf(str, "%d", x);
    return (strlen(str));
}

int convStrToInt(char *str){
    int result = 0;
    int i = 0;
    for (i; str[i] != '\0'; i++){
        result = result*10 + str[i] - '0';
    }
    return result;
}

int isDigit(int c){
    if(c >= '0' && c <= '9'){
        return 1;
    } else {
        return 0;
    }
}
