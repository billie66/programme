#include <stdio.h>
// Token concatenation using "##" preprocessor operator
#define FRUIT(name, num)  name##_##num = num; 

int main(int argc, const char *argv[])
{
    int apple_5;
    FRUIT(apple, 5)
    printf("apple_5: %d\n", apple_5);
    return 0;
}
