#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <cuda_tid.h>

#define NUM_DATA 10240
#define BLOCK_MAX 1024
#define IS_HOST_CAL 0

__global__ void vec_Add(int* _a, int* _b, int* _c)
{
    int tID = GRID_1D_BLOCK_1D_TID;
    _c[tID] = _a[tID] + _b[tID];
}

int main(void)
{
    int* a = nullptr;
    int* b = nullptr;
    int* c = nullptr;

    int* d_a = nullptr;
    int* d_b = nullptr;
    int* d_c = nullptr;

    int mem_size = sizeof(int) * NUM_DATA;
    printf("%d elements, mem_size = %d bytes\n", NUM_DATA, mem_size);

    a = new int[NUM_DATA];
    b = new int[NUM_DATA];
    c = new int[NUM_DATA];

    memset(a, 0, mem_size);
    memset(b, 0, mem_size);
    memset(c, 0, mem_size);

    for (int i = 0; i < NUM_DATA; i++)
    {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }

#if IS_HOST_CAL
    time_t start = time(NULL);

    for (int i = 0; i < NUM_DATA; i++)
        c[i] = a[i] + b[i];

    time_t end = time(NULL);
#else
    cudaMalloc(&d_a, mem_size);
    cudaMalloc(&d_b, mem_size);
    cudaMalloc(&d_c, mem_size);

    cudaMemcpy(d_a, a, mem_size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, mem_size, cudaMemcpyHostToDevice);

    time_t start = time(NULL);
    dim3 block(BLOCK_MAX);
    dim3 grid((BLOCK_MAX + NUM_DATA - 1) / BLOCK_MAX);
    vec_Add<<<grid, block>>>(d_a, d_b, d_c);
    cudaDeviceSynchronize();
    time_t end = time(NULL);

    cudaMemcpy(c, d_c, mem_size, cudaMemcpyDeviceToHost);

    bool is_result = true;
    for (int i = 0; i < NUM_DATA; i++)
    {
        if((a[i] + b[i]) != c[i])
        {
            printf("[%d] The results is not matched! (%d, %d)\n", i, a[i] + b[i], c[i]);
            is_result = false;
        }
    }

    if(is_result) printf("GPU works well!\n");

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
#endif
    delete[] a;
    delete[] b;
    delete[] c;

    printf("Total Time : [%lf] ms\n", (double)end-start);
    return 0;
}