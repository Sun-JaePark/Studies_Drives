#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd = 0;
    int n = 0;
    off_t start = 0;
    off_t cur = 0;
    char buf[256] = {0, };

    fd = open("linux.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("Open linux.txt");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);
    n = read(fd, (void*) buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);
    cur = lseek(fd, 0, SEEK_CUR);
    printf("Offset cur=%d\n", (int)cur);

    start = lseek(fd, 6, SEEK_SET);
    n = read(fd, (void*) buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);

    close(fd);

    return 0;
}