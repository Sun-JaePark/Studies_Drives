#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define IS_LOCK 1

union semun
{
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

int initsem(key_t _semkey);
int semlock(int _semid);
int semunlock(int _semid);
void semhandle(void);

int main(void)
{
    int a = 0;

    for(a = 0; a < 3; a++)
        if(fork() == 0) semhandle();

    return 0;
}

int initsem(key_t _semkey)
{
    union semun semunarg;
    int status = 0;
    int semid = 0;

    semid = semget(_semkey, 1, IPC_CREAT | IPC_EXCL | 0600);
    if(semid == -1)
    {
        if(errno == EEXIST) semid = semget(_semkey, 1, 0);
    }
    else
    {
        semunarg.val = 1;
        status = semctl(semid, 0, SETVAL, semunarg);
    }

    if(semid == -1 || status == -1)
    {
        perror("initsem");
        return -1;
    }
    return semid;
}

int semlock(int _semid)
{
    struct sembuf buf;

    buf.sem_num = 0;
    buf.sem_op = -1; //P(s)
    buf.sem_flg = SEM_UNDO;

    if(semop(_semid, &buf, 1) == -1)
    {
        perror("semlock failed");
        exit(1);
    }

    return 0;
}

int semunlock(int _semid)
{
    struct sembuf buf;

    buf.sem_num = 0;
    buf.sem_op = 1; //V(s)
    buf.sem_flg = SEM_UNDO;

    if(semop(_semid, &buf, 1) == -1)
    {
        perror("semunlock failed");
        exit(1);
    }

    return 0;
}

void semhandle(void)
{
    int semid = 0;
    pid_t pid = getpid();

    if((semid = initsem(1)) < 0) exit(1);

#if IS_LOCK
    semlock(semid);
#endif
    printf("Lock : Process %d\n", (int)pid);
    printf("** Lock Mode : Critical Section\n");
    sleep(1);
    printf("Unlock : Process %d\n", (int)pid);
#if IS_LOCK
    semunlock(semid);
#endif

    exit(0);
}
