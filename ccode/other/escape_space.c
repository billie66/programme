#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strcat1(char *dest, const char *src)
{
    size_t i;
    size_t src_len = strlen(src);

    dest[0] = '\"';
    for (i = 0 ; src[i] != '\0' ; i++)
        dest[i+1] = src[i];
    dest[src_len + 1] = '\"';
    dest[src_len + 2] = '\0';

    return dest;
}

int main(int argc, const char *argv[])
{
    const char *fname = "dd cc";
    const char *cname = "中文 字符";
    const char *tmp = fname; 
    char c = '\\';
    int len, total, len1, clen; 
    len = sizeof(fname);
    clen = sizeof(cname);
    total = 2 * len;
    char vim_cmd[30];
    
    char localname[total];
    char local[20];
    strcat1(local, argv[1]);
    int i, j;
    for (i = 0, j = 0; j < len; tmp++, j++)
    {
        if (*tmp == ' ')
        {
            localname[i++] = '\\';
            localname[i++] = ' ';
            continue;
        }
        localname[i++] = *tmp;
    }
    localname[i] = '\0';
    tmp = localname;
    snprintf(vim_cmd, sizeof(vim_cmd), "vim %s", tmp);
    
    printf("localname %s \n", localname);
    printf("len %d \n", len);
    printf("clen %d \n", clen);
    printf("len1 %d \n", sizeof localname/ sizeof localname[0]);
    printf("local%s \n", local);
    printf("c %c \n", c);
    return 0;
}

