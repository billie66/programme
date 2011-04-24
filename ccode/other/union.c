#include <stdio.h>

int main(int argc, char *argv[])
{
    union zoo {
        unsigned char b[2];
        int a;
    } x;

    x.a = 256;
    printf("b is %d\n", x.b[0]);
    printf("b1 is %d\n", x.b[1]);
    printf("sizeof %d\n", sizeof(x));
    printf("sizeof %d\n", sizeof(char *));

    return 0;
}
