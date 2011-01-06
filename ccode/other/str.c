#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *a = "a";
    char *b = "he";
    static const char str[] = 
    "tig: \n"
    "usage: hello\n"
    "\n"
    "print: \n";
    printf("the str is:\n %s", str);
    printf("the len of str is: %d\n", sizeof(str));
    if (!strcasecmp(a, b))
        printf("a less than b\n");
    signed int result;
    result = strcasecmp(a, b);
    printf("result: %d\n", result);
    return 0;
}
