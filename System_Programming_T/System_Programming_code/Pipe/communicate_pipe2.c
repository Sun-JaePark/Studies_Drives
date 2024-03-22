#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int pd1 = 0;
    int pd2 = 0;
    int n = 0;
    char msg[] = "Hello, Commu_1";
    char inmsg[80] = {0, };

    printf("COMMU_PIPE_2 ======\n");
    if((pd1 = open("./pipeFile1", O_RDONLY)) == -1)
    {
        perror("open");
        exit(1);
    }

    if((pd2 = open("./pipeFile2", O_WRONLY)) == -1)
    {
        perror("open");
        exit(1);
    }

    printf("To Commu_1 : %s\n", msg);
    n = write(pd2, msg, strlen(msg) + 1);

    if(n == -1)
    {
        perror("write");
        exit(1);
    }

    close(pd2);

    write(1, "From Commu_1 : ", 15);
    while((n = read(pd1, inmsg, 80)) > 0)
        write(1, inmsg, n);

    if(n == -1)
    {
        perror("read");
        exit(1);
    }
    write(1, "\n", 1);

    close(pd1);

    return 0;
}