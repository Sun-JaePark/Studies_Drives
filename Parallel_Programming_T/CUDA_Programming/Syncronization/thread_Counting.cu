#include <cuda_tid.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

__global__ void threadCounting_Ver1(int* _d)
{
    (*_d)++;
}

__global__ void threadCounting_Ver2(int* _d)
{
    atomicAdd(_d, 1);
}

__global__ void threadCounting_Ver3(int* _d)
{
    __shared__ int sa;

    if(threadIdx.x == 0) sa = 0;

    __syncthreads();

    atomicAdd(&sa, 1);

    __syncthreads();

    if(threadIdx.x == 0) atomicAdd(_d, sa);
}

int main(int argc, char** argv)
{
    clock_t start = NULL;
    clock_t end = NULL;

    int a = 0;
    int *d1 = nullptr;
    int *d2 = nullptr;
    int *d3 = nullptr;

    cudaMalloc((void**)&d1, sizeof(int));
    cudaMalloc((void**)&d2, sizeof(int));
    cudaMalloc((void**)&d3, sizeof(int));
    cudaMemset(d1, 0, sizeof(int) * 1);
    cudaMemset(d2, 0, sizeof(int) * 1);
    cudaMemset(d3, 0, sizeof(int) * 1);

    dim3 block_size(512);
    dim3 grid_size(10240);

    start = clock();
    threadCounting_Ver1<<<grid_size, block_size>>>(d1);
    cudaDeviceSynchronize();
    end = clock();

    cudaMemcpy(&a, d1, sizeof(int), cudaMemcpyDeviceToHost);

    printf("No_Sync res >> %d\n", a);
    printf("No_Sync time >> %lf s\n\n", (double)(end-start) / CLOCKS_PER_SEC);

    start = clock();
    threadCounting_Ver2<<<grid_size, block_size>>>(d2);
    cudaDeviceSynchronize();
    end = clock();

    cudaMemcpy(&a, d2, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Global_Atomic res >> %d\n", a);
    printf("Global_Atomic time >> %lf s\n\n", (double)(end-start) / CLOCKS_PER_SEC);

    start = clock();
    threadCounting_Ver3<<<grid_size, block_size>>>(d3);
    cudaDeviceSynchronize();
    end = clock();

    cudaMemcpy(&a, d3, sizeof(int), cudaMemcpyDeviceToHost);

    printf("Shared_Atomic res >> %d\n", a);
    printf("Shared_Atomic time >> %lf s\n", (double)(end-start) / CLOCKS_PER_SEC);

    return 0;
}
