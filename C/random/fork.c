#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        exit(-1);
    }
    else if (pid == 0) { /* child process */
        execlp("ls", "ls", NULL); // Use "ls" instead of a directory path
        fprintf(stderr, "Exec Failed\n");
        exit(-1);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
}

