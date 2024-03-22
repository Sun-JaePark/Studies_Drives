#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHECK_MMAP_SUCCESS(_addr)\
if(_addr == MAP_FAILED)\
{\
    perror("mmap");\
    exit(1);\
}

int main(int argc, char **argv)
{
    int fd = 0;
    int pid = 0;
    __caddr_t addr = 0;
    char file_name[255] = "input.dat";

    if(argc > 1) strcpy(file_name, argv[1]);

    if((fd = open(file_name, O_RDWR)) == -1)
    {
        perror("open");
        exit(1);
    }

    int page_size = getpagesize();

    addr = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0);
    CHECK_MMAP_SUCCESS(addr);

    close(fd);

    switch (pid = fork())
    {
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            printf("1. Child Process : addr = %s", addr);

            sleep(1);
            addr[0] = 'x';
            printf("2. Child Process : addr = %s", addr);
            
            sleep(2);
            printf("3. Child Process : addr = %s", addr);
            break;
        
        default:
            printf("1. Parent Process : addr = %s", addr);

            sleep(2);
            printf("2. Parent Process : addr = %s", addr);
        
            addr[1] = 'y';
            printf("3. Parent Process : addr = %s", addr);
            break;
    }
    return 0;
}
