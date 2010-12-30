#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    int len;
    char buf[100];
    char *line;
    fp = popen("ls", "r");
    while (line = fgets(buf, sizeof(buf), fp)) {
        len = strlen(line);
        printf("%d\n", len);
        printf("%s", line);
    }
    pclose(fp);
    return 0;
}

