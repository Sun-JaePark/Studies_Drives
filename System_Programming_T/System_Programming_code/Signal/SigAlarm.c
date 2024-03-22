#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int _signo);

int main(void)
{
    signal(SIGALRM, handler);

    alarm(2);
    printf("Wait...\n");
    sleep(3);
    
    return 0;
}


void handler(int _signo)
{
    psignal(_signo, "Received Signal");
}