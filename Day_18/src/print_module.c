#include <stdio.h>
#include <time.h>
#include "print_module.h"


void print_log(char (*print)(char), char* message) {
    int hours, minutes, seconds;
    int i = 0;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;
    printf(Log_prefix" %02d:%02d:%02d ", hours, minutes, seconds);
    while (message[i] != '\0') {
        print(message[i]);
        i++;
    }
}

char print_char(char ch)  {
    return putchar(ch);
}
