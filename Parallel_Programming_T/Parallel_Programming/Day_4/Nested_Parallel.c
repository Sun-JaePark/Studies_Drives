#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    int set_nested = strtol(argv[1], NULL, 10);
    int threads = strtol(argv[2], NULL, 10);
    int nested_threads = strtol(argv[3], NULL, 10);

    omp_set_nested(set_nested);
    printf("Nested parallelism : %s\n", set_nested ? "On" : "Off");

    #pragma omp parallel num_threads(threads)
    {
        int parentID = omp_get_thread_num();
        printf("Lv.1 - Thread %d\n", parentID);
        #pragma omp parallel num_threads(nested_threads)
            printf("\tLv.2 - Thread %d of %d\n", omp_get_thread_num(), parentID);
    }
    return 0;
}