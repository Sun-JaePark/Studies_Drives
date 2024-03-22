#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define COMBINE 1

int main(int argc, char* argv[])
{

#if COMBINE
    #pragma omp parallel for
    for (int i = 0; i < 12; i++)
        printf("[Thread %d] executes loop iteration %d\n", omp_get_thread_num(), i);
#else
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 16; i++)
            printf("[Thread %d] executes loop iteration %d\n", omp_get_thread_num(), i);
    }
#endif
    return 0;
}