#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void test(int _val);

int main(int argc, char* argv[])
{
    omp_set_num_threads(argc - 1);

    for (int i = 0; i < argc - 1; i++)
        test(strtol(argv[i + 1], NULL, 10));
    return 0;
}

void test(int _val)
{
    #pragma omp parallel if(_val)
    if(omp_in_parallel())
    {
        #pragma omp single
        printf("val = %d, parallelized with %d threads\n", 
        _val, omp_get_num_threads());
    }
    else
        printf("val = %d, serialized\n", _val);
}

