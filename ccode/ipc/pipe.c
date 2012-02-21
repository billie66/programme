/* copy from linux programmer's manual pipe(2) */

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    int pipefd[2];
    int pipefdd[2];
    pid_t cpid;
    pid_t dpid;
    char buf;
    int a;

    if (argc != 2) {
     fprintf(stderr, "Usage: %s <string>\n", argv[0]);
     exit(EXIT_FAILURE);
    }
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    fprintf(stdout, "cpid: %d \n", cpid);

    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* Child reads from pipe */
        close(pipefd[1]);          /* Close unused write end */

        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */

        if (pipe(pipefdd) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        dpid = fork();
        fprintf(stdout, "dpid: %d \n", dpid);

        if (dpid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (dpid == 0) {
            close(pipefdd[1]);          /* Close unused write end */

            while (read(pipefdd[0], &buf, 1) > 0)
                write(STDOUT_FILENO, &buf, 1);

            write(STDOUT_FILENO, "\n", 1);
            close(pipefdd[0]);
            _exit(EXIT_SUCCESS);

        } else {
            close(pipefdd[0]);          /* Close unused read end */
            write(pipefdd[1], argv[1], strlen(argv[1]));
            close(pipefdd[1]);          /* Reader will see EOF */
            wait(NULL);                /* Wait for child */
            exit(EXIT_SUCCESS);
        }
   }
}    

