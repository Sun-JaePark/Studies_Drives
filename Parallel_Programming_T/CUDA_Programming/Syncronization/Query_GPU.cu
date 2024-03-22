#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int ngpus = 0;
    cudaGetDeviceCount(&ngpus);

    for (int i = 0; i < ngpus; i++)
    {
        cudaDeviceProp devProp;

        cudaGetDeviceProperties(&devProp, i);
        printf("Device[%d] (%s) compute capability : %d.%d.\n", i, devProp.name, devProp.major, devProp.minor);
        printf("maxThreadsDim[1] // [2] // [3] : %d, %d, %d\n", devProp.maxThreadsDim[0], devProp.maxThreadsDim[1], devProp.maxThreadsDim[2]);
        printf("maxGridSize : %d\n", *devProp.maxGridSize);
        printf("maxThreadsPerBlock : %d\n", devProp.maxThreadsPerBlock);
    }
    
    return 0;
}