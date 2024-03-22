#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char* argv[])
{
    int vector_size = strtol(argv[1], NULL, 10);
    int numThreads = strtol(argv[2], NULL, 10);
    int numElePerThread = vector_size / numThreads;

    int* start = new int[numThreads];
    int* end = new int[numThreads];

    int a[vector_size] = {0, };
    int b[vector_size] = {0, };
    int c[vector_size] = {0, };

    for(int i = 0; i < vector_size; i++)
        a[i] = i;

    for (int j = vector_size - 1; j >= 0; j--)
        b[vector_size - j - 1] = j;

    printf("Work decomposition\n");
    for(int tID = 0; tID < numThreads; tID++)
    {
        start[tID] = numElePerThread * tID;
        end[tID] = numElePerThread * (tID + 1);

        if(tID == numThreads - 1)
            end[numThreads - 1] = vector_size;

        printf("\t[T%d] %d ~ %d\n", tID, start[tID], end[tID]);
    }

    printf("{");
    #pragma omp parallel num_threads(numThreads)
    {
        int tID = omp_get_thread_num();

        for(int i = start[tID]; i < end[tID]; i++)
        {
            c[i] = a[i] + b[i];
            printf("%d, ", c[i]);
        }
    }
    printf("}\n");
    return 0;
}