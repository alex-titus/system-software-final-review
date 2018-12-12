/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task2 task2.c


*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd1 = open("/var/run/utmpp", O_RDONLY);
    if(fd1 <= 0)
    {
        printf("Unable to open utmp file\n");
        exit(1);
    }

    int bRead;
    char b;

    while((bRead = read(fd1, &b, 1)) > 0)
    {
        printf("%s", &b);
    }

    int count = 0;

    setutent(); // Rewind point to beginning of utmp file

    struct utmp *t = getutent(); // Reads line from current file positon of utmp

    while(t != NULL)
    {
        if(t->ut_type == USER_PROCESS)
        {
            printf("User %d: %s\n",count, t->ut_user);
            count++;
        }
        t = getutent();
    }

    printf("Count of users logged in: %d\n", count);

    close(fd1);
    endutent();
    return 0;
}
