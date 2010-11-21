#include <stdio.h>
#include <string.h>

char b[200];
char *swap (char a[])
{
    int i = 0, j=0, k=0;
    char c[100];
    while(a[i++]!='\0'){
        if(a[i] == ' '){
            while(a[i++]!='\0'){
                b[j] = a[i];
                j++;
            }
        b[j-1] = ' ';
        b[j] = '\0';
        }
    }
    i = 0;
    while(a[i++] != ' '){
        c[k] = a[i-1];
        k++;
    }
    c[k] = '\0';
    return strcat(b,c);
}

int main(int argc, const char *argv[])
{
    char a[100];
    int len, i = 0;
    printf("input character:\n");
    while( (a[i++] = getchar()) != '\n')
        ;
    a[i-1] = '\0';
    printf("now inppppp: %s \n", a);

    printf("output string:\n");
   
    printf("%s\n", swap(a));
    return 0;
}
