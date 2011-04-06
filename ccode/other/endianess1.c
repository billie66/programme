#include <stdio.h>

int main()
{
    int a = 1;
    if (*(char *)&a == 1)
        printf("little-endian\n");
    else
        printf("big-endian\n");
    return 0;
}
