#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int status = 0;
    pid_t pid = 0;

    if((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if(pid == 0)
    {
        printf("--> Child process\n");
        sleep(3);
        exit(3);
    }

    printf("--> Parent process\n");
    while(waitpid(pid, &status, WNOHANG) == 0)
    {
        printf("Parent still wait...\n");
        sleep(1);
    }
    printf("Child Exit Status: %d\n", WEXITSTATUS(status));
    
    return 0;
}