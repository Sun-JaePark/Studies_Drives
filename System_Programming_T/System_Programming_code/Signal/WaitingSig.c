#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int _signo);

int main(void)
{
    sigset_t set;
    signal(SIGALRM, handler);

    sigfillset(&set);
    sigdelset(&set, SIGALRM);

    alarm(3);

    printf("Wait...\n");

    sigsuspend(&set);
    
    return 0;
}


void handler(int _signo)
{
    psignal(_signo, "Received Signal:");
}