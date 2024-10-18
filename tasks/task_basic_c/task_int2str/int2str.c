#include <stdio.h>
#include "int2str.h"

char* int2str(int value) {
    static char buffer[12]; 
    char* ptr = buffer;     
    long long num = (long long)value; 
    int isNegative = 0;

    if (num == 0) {
        return "0";
    }
    
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        *ptr++ = (num % 10) + '0';
        num /= 10;
    }

    if (isNegative) {
        *ptr++ = '-';
    }

    char* start = buffer;
    char* end = ptr - 1;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    return buffer;
}
