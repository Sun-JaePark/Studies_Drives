#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd = 0;
    int fd1 = 0;

    fd = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(fd == -1)
    {
        perror("Create tmp.aaa");
        exit(1);
    }

    close(1);

    fd1 = dup(fd);
    printf("DUP FD=%d\n", fd1);
    printf("Standard Output Redirection\n");

    close(fd);

    return 0;
}