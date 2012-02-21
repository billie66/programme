#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    const char *fname = "dd cc";
    const char *cname = "中文 字符";
    const char *tmp = fname; 
    char c = '\\';
    int len, total, len1, clen; 
//    len = strlen(fname);
//    clen = strlen(cname);
    len = sizeof(fname);
    clen = sizeof(cname);
    total = 2 * len;
    char vim_cmd[30];
    
    char localname[total];
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
//    system(vim_cmd);
    printf("c %c \n", c);
    return 0;
}
