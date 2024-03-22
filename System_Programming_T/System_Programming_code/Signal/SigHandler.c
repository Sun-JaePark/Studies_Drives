#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int _signo);

int main(void)
{
    if(signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGINT!\n");
        exit(EXIT_FAILURE);
    }

    for(;;) pause();
    
    return 0;
}

void sigint_handler(int _signo)
{
    printf("Caught SIGINT!\n");
    psignal(_signo, "Received signal");
}