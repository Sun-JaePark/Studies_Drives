#include <sys/sysinfo.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    struct sysinfo sinfo;
    if(sysinfo(&sinfo) == -1)
    {
        perror("sysinfo");
        exit(1);
    }

    printf("Uptime : %ld\n", sinfo.uptime);
    printf("Load[0] : %ld\n", sinfo.loads[0]);
    printf("Load[1] : %ld\n", sinfo.loads[1]);
    printf("Load[2] : %ld\n", sinfo.loads[2]);
    printf("TotalRam : %ld\n", sinfo.totalram);
    printf("FreeRam : %ld\n", sinfo.freeram);
    printf("SharedRam : %ld\n", sinfo.sharedram);
    printf("BufferRam : %ld\n", sinfo.bufferram);
    printf("TotalSwap : %ld\n", sinfo.totalswap);
    printf("FreeSwap : %ld\n", sinfo.freeswap);
    printf("Current PS : %d\n", sinfo.procs);

    return 0;
}