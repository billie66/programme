#include <stdio.h>

int main(int argc, const char *argv[])
{
    union date {
        int day;
        char str[sizeof(int)];
    }ta;
    
    ta.day = 1;
    if (ta.str[0] == 1) 
        printf("It is little-endian\n");
    else
        printf("It is big-endian\n");

    return 0;
}
