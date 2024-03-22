#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define COMBINE 1

int main(int argc, char* argv[])
{
    int threads = strtol(argv[1], NULL, 10);
#if COMBINE
        #pragma omp parallel sections num_threads(threads)
        {
            #pragma omp section
            printf("Section A executed by thread %d\n", omp_get_thread_num());
            #pragma omp section
            printf("Section B executed by thread %d\n", omp_get_thread_num());
        }
#else
    #pragma omp parallel num_threads(threads)
    {
        #pragma omp sections
        {
            #pragma omp section
            printf("Section A executed by thread %d\n", omp_get_thread_num());
            #pragma omp section
            printf("Section B executed by thread %d\n", omp_get_thread_num());
        }
    }
#endif
    return 0;
}