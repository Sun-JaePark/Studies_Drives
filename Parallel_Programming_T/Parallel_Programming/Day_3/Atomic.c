#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define IS_ATOM 1

int main(int argc, char* argv[])
{
    int ic = 0;
    int loop = strtol(argv[1], NULL, 10);
    int threads = strtol(argv[2], NULL, 10);

    #pragma omp parallel num_threads(threads)
    {
        for (int i = 0; i < loop; i++)
        {
#if IS_ATOM
            #pragma omp atomic
#endif
            ic++;
        }
        
    }
    printf("count = %d\n", ic);
    return 0;
}
