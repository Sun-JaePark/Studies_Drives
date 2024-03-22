#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define COMBINE 1
using namespace std;

int main(int argc, char* argv[])
{
    int vector_size = strtol(argv[1], NULL, 10);
    int numThreads = strtol(argv[2], NULL, 10);

    int a[vector_size] = {0, };
    int b[vector_size] = {0, };
    int c[vector_size] = {0, };

    for(int i = 0; i < vector_size; i++)
        a[i] = i;

    for (int j = vector_size - 1; j >= 0; j--)
        b[vector_size - j - 1] = j;

    printf("Work decomposition\n");
    printf("{");
#if COMBINE
    #pragma omp parallel for num_threads(numThreads)
    for (int i = 0; i < vector_size; i++)
    {
        c[i] = a[i] + b[i];
        printf("%d, ", c[i]);
    }
#else
    #pragma omp parallel num_threads(numThreads)
    {
        #pragma omp for
        for (int i = 0; i < vector_size; i++)
        {
            c[i] = a[i] + b[i];
            printf("%d, ", c[i]);
        }
    }
#endif

    printf("}\n");
    return 0;
}