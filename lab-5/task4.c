/*  This software code is provided as open source software. No questions will be
    answered relating to any part of this software, for any reason.

    Much love,
    https://github.com/alex-titus
    gcc -o task4 task4.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

char *myasctime(const struct tm *timeptr);

int main(int argc, char **argv)
{
    char *result[26];
	time_t t = time((time_t *)NULL);
	*result = asctime((localtime(&t)));

	printf("The current asctime in string is: %s", *result);
}

char *myasctime(const struct tm *timeptr)
{
    static const char *wday_name[] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    static const char *mon_name[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
     };
    static char result[26];
        sprintf(result, "%s %s %d %d:%d:%d %d\n", //Modded values to keep in range
        wday_name[(timeptr->tm_wday)%7],
        mon_name[(timeptr->tm_mon)%12],
        timeptr->tm_mday%32, timeptr->tm_hour%24,
        timeptr->tm_min%60, timeptr->tm_sec%61,
        1900 + timeptr->tm_year
        );
    return result;
}
