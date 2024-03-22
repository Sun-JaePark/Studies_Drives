#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp = NULL;
    int fd = 0;
    char str[BUFSIZ] = {0, };

    fd = open("hello.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        exit(1);    
    }

    fp = fdopen(fd, "r");

    fgets(str, BUFSIZ, fp);
    printf("Read : %s\n", str);

    fclose(fp);

    return 0;
}