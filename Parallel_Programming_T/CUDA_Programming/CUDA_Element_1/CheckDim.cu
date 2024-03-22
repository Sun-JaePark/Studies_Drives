#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

__global__ void check_Index(void)
{
    printf("threadIdx:(%d, %d, %d) blockIdx:(%d, %d, %d) blockDim:(%d, %d, %d) gridDim:(%d, %d, %d)\n",
    threadIdx.x, threadIdx.y, threadIdx.z,
    blockIdx.x, blockIdx.y, blockIdx.z,
    blockDim.x, blockDim.y, blockDim.z,
    gridDim.x, gridDim.y, gridDim.z);
}

int main(int argc, char** argv)
{
    int n_elem = 40;
    dim3 block(5, 1, 2);
    int block_size = block.x * block.y * block.z;
    dim3 grid((n_elem + block_size - 1) / block_size);

    printf("grid.x %d grid.y %d grid.z %d\n", grid.x, grid.y, grid.z);
    printf("block.x %d block.y %d block.z %d\n", block.x, block.y, block.z);

    check_Index <<<grid, block>>>();
    cudaDeviceReset();

    return 0;
}