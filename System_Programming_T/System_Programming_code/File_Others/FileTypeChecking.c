#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
    struct stat buf;
    int kind = 0;
    
    stat("linux.txt", &buf);

    printf("Mode = %o (Hexa: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    kind = buf.st_mode & __S_IFMT;
    printf("Kind = %x\n", kind);

    switch (kind)
    {
        case __S_IFIFO:
            printf("linux.txt : FIFO\n");        
            break;
        case __S_IFDIR:
            printf("linux.txt : Directory\n");        
            break;
        case __S_IFREG:
            printf("linux.txt : Regular File\n");        
            break;
        default:
            break;
    }

    return 0;
}