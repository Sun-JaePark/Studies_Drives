#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_MMAP_SUCCESS(_addr)\
if(_addr == MAP_FAILED)\
{\
    perror("mmap");\
    exit(1);\
}

int main(int argc, char** argv)
{
    int fd = 0;
    __caddr_t addr = 0;
    char file_name[255] = "map.dat";

    if(argc > 1) strcpy(file_name, argv[1]);
    if((fd = open(file_name, O_RDWR)) == -1)
    {
        perror("open");
        exit(1);
    }
    addr = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0);
    CHECK_MMAP_SUCCESS(addr);
    
    close(fd);

    while(1)
    {
        sleep(2);
        printf("%c\n", addr[0]);
    }
    return 0;
}