#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    int sum = 0;
    int n = strtol(argv[1], NULL, 10);

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++)
        sum += i;
    printf("result >> %d\n", sum);
    return 0;
}