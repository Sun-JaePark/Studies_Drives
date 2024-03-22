#include <iostream>
#include <omp.h>

#define COMBINE 1

int main(int argc, char* argv[])
{
    int size = strtol(argv[1], NULL, 10);
    int a[size] = {0, };
    int b[size] = {0, };

#if COMBINE
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
        a[i] = i;
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
        b[i] = 2 * a[i];
#else
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < size; i++)
            a[i] = i;
        #pragma omp for
        for (int i = 0; i < size; i++)
            b[i] = 2 * a[i];
    }
#endif
    printf("{");
    for (int i = 0; i < size; i++)
        printf("%d, ", b[i]);
    printf("}\n");
    
    return 0;
}