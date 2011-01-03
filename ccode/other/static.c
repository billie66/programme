#include <stdio.h>

static int sg;
int global;
int sum(int a)
{
    static int sum = 0;
    sum += a;
    return sum;
}

static int add(int a, int b)
{
    static int c = 0;
    sg = 2;
    return c += a + b;
}

int main(int argc, const char *argv[])
{
    int a, i;
    for (i = 1; i < 4; i++)
    {
        a = sum(i);
        printf("output a: %d\n", a);
    }
    int total;
    total = add(2, 3);
    total = add(3, 4);
    printf("print total: %d\n", total);
    static int b;
    printf("print p: %d\n", b);
    printf("print global: %d\n", global);
    sg += 3;
    printf("print sg: %d\n", sg);
    
    return 0;
}
