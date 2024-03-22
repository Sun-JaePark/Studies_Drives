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

#define PRINT_ADDRS(_msg)\
{\
    printf("%s\n", _msg);\
    printf("addr1 = %s", addr1);\
    printf("addr2 = %s", addr2);\
}

int main(int argc, char **argv)
{
    int fd = 0;
    __caddr_t addr1 = 0;
    __caddr_t addr2 = 0;
    char file_name[255] = "input.dat";

    if(argc > 1) strcpy(file_name, argv[1]);

    if((fd = open(file_name, O_RDWR)) == -1)
    {
        perror("open");
        exit(1);
    }

    int page_size = getpagesize();

    addr1 = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0);
    CHECK_MMAP_SUCCESS(addr1);

    addr2 = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, (off_t)0);
    CHECK_MMAP_SUCCESS(addr2);

    close(fd);

    printf("%s", addr1);

    addr1[0] = '1';
    PRINT_ADDRS("After addr1[0] = 1");

    addr2[0] = '2';
    PRINT_ADDRS("After add2[0] = 2");

    addr1[0] = '3';
    PRINT_ADDRS("After addr1[0] = 3");

    execlp("cat", "cat", file_name, NULL);

    return 0;
}