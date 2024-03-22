#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//gcc -g -Wall -fopenmp -o omp_hello Hello_OpenMP.c
int main(int argc, char *argv[])
{
    int thread_count = strtol(argv[1], NULL, 10);

    #pragma omp parallel num_threads(thread_count)
    printf("[Thread %d] Hello OpenMP!\n", omp_get_thread_num());
    return 0;
}