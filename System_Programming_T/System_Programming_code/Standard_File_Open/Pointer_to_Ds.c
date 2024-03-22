#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    FILE* fp = NULL;
    int fd = 0;
    int n = 0;
    char str[BUFSIZ] = {0, };

    fp = fopen("hello.txt", "r");
    if(!fp)
    {   
        perror("fopen");
        exit(1);
    }

    fd = fileno(fp);
    printf("fd: %d\n", fd);

    n = read(fd, str, BUFSIZ);
    str[n] = '\0';
    printf("Read : %s\n", str);

    close(fd);

    return 0;
}