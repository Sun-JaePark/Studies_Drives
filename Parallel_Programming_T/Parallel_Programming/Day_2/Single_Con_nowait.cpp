#include <iostream>
#include <omp.h>


int main(int argc, char* argv[])
{
    int size = strtol(argv[2], NULL, 10);
    int a = 0;
    int b[size] = {0, };
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            a = strtol(argv[1], NULL, 10);
            printf("Single construct executed by thread %d\n", omp_get_thread_num());
        }
        #pragma omp for
        for (int i = 0; i < size; i++)
            b[i] = a;
    }
    for (int i = 0; i < size; i++)
        printf("b[%d] = %d\n", i, b[i]);
    return 0;
}