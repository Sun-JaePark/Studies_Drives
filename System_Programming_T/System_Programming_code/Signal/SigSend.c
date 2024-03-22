#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

extern int errno;

int main(void)
{
    int target_PID = 0;

    while(1)
    {
        printf("Enter PID to kill : ");
        scanf("%d", &target_PID);
        if(kill(target_PID, SIGKILL) == -1)
        {
            switch (errno)
            {
                case EPERM:
                    printf("Not enough permission\n");
                    break;

                case ESRCH:
                    printf("Cannot find the process %d\n", target_PID);
                    break;

                default:
                    break;
            }
        }
        else printf("Bang! -> %d\n", target_PID); 
    }
    return 0;
}