#include "extern.h" 

extern int b;
extern char r;
int ff = 4;
extern int tt;
int ddd;

int main(int argc, const char *argv[])
{
    int f = 3;
    ddd = 2;
    printf("extern variable b: %d\n", b);
    printf("variable f: %d\n", f);
    fun();
    add();
    printf("variable r: %c\n", r);
    printf("variable dd: %d\n", dd);
    printf("variable ff: %d\n", ff);
    printf("variable tt: %d\n", tt);
    printf("variable ddd: %d\n", ddd);
    return 0;
}
