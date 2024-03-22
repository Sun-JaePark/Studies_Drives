#include <iostream>
#include <omp.h>

#define IS_BAR 1

int main(int argc, char* argv[])
{
    int threads = strtol(argv[1], NULL, 10);
    int size = strtol(argv[2], NULL, 10);
    int a[threads] = {0, };
    int b[size] = {0, };

    #pragma omp parallel num_threads(threads)
    {
        int tID = omp_get_thread_num();
        a[tID] = tID * 10;
        printf("a : %2d tID : %2d\n", a[tID], tID);
#if IS_BAR
        #pragma omp barrier
#endif

        #pragma omp for
        for (int i = 0; i < size; i++)
            b[i] = 2 * a[(i + 1) % threads];
    }
    
    for (int i = 0; i < size; i++)
        printf("b[%2d] b : %2d\n", i, b[i]);
    
    return 0;
}