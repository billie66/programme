/* Token concatenation using "##" preprocessor operator */

#include <stdio.h>
#include <stdbool.h>  // C99 does define a standard Boolean type.

#define FRUIT(name, num)  name##_##num = num 

int main(int argc, const char *argv[])
{
    int apple_5;
    bool flag;
    struct line {
        unsigned int a:2;
    }b;

    printf("b.a: %d\n", b.a);

    FRUIT(apple, 5);
    printf("apple_5: %d\n", apple_5);

    if (flag = true)
        printf("flag: %d\n", flag);

    return 0;
}
