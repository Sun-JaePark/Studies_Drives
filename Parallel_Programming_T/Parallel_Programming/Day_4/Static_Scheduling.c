#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    int loop = strtol(argv[1], NULL, 10);
    int chunk = strtol(argv[2], NULL, 10);
    int threads = strtol(argv[3], NULL, 10);
    
    #pragma omp parallel for schedule(static, chunk) num_threads(threads)
    for (int i = 0; i < loop; i++)
    {
        int tID = omp_get_thread_num();
        printf("[%d] by thread %d\n", i, tID);
    }
    return 0;
}