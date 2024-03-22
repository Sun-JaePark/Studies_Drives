#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
    struct stat buf;
    int kind = 0;
    
    stat("linux.txt", &buf);

    printf("Mode = %o (Hexa: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    if(S_ISFIFO(buf.st_mode)) printf("linux.txt: FIFO\n");
    if(S_ISDIR(buf.st_mode)) printf("linux.txt: Directory\n");
    if(S_ISREG(buf.st_mode)) printf("linux.txt: Regular File\n");

    return 0;
}