#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int fd1[2] = {0, };
    int fd2[2] = {0, };
    pid_t pid = 0;
    char buf[257] = {0, };
    int len = 0;
    int status = 0;

    if(pipe(fd1) == -1)
    {
        perror("pipe");
        exit(1);
    }

    if(pipe(fd2) == -1)
    {
        perror("pipe");
        exit(1);
    }

    switch (pid = fork())
    {
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            close(fd1[1]);
            close(fd2[0]);
            write(1, "Child Process:", 15);
            len = read(fd1[0], buf, 256);
            write(1, buf, len);

            strcpy(buf, "Good\n");
            write(fd2[1], buf, strlen(buf));
            break;
        
        default:
            close(fd1[0]);
            close(fd2[1]);
            buf[0] = '\0';
            write(fd1[1], "Hello\n", 6);

            sleep(1);
            write(1, "Parent Process:", 15);
            len = read(fd2[0], buf, 256);
            write(1, buf, len);
            waitpid(pid, &status, 0);
            break;
    }
    return 0;
}