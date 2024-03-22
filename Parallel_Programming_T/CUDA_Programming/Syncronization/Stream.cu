#include <cuda_tid.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define NUM_BLOCK (128 * 1024)
#define NUM_T_IN_B 1024
#define ARRAY_SIZE (NUM_T_IN_B * NUM_BLOCK)
#define WORK_LOAD 10240

#define NUM_STREAMS 1024

__global__ void my_kernel(int* _input, int* _output)
{
    int index = GRID_1D_BLOCK_1D_TID;

    int temp = 0;
    for (int i = 0; i < WORK_LOAD; i++)
        temp = (temp + _input[index] * 5) % 10;

    _output[index] = temp;
}

int main(void)
{
    clock_t start = NULL;
    clock_t end = NULL;

    int* in = nullptr;
    int* out = nullptr;

    int* din = nullptr;
    int* dout = nullptr;

    cudaMallocHost(&in, sizeof(int)*ARRAY_SIZE);
    memset(in, 0, sizeof(int)*ARRAY_SIZE);
    cudaMallocHost(&out, sizeof(int)*ARRAY_SIZE);
    memset(out, 0, sizeof(int)*ARRAY_SIZE);

    cudaMalloc(&din, sizeof(int)*ARRAY_SIZE);
    cudaMalloc(&dout, sizeof(int)*ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
        in[i] = rand() % 10;

    start = clock();
    cudaMemcpy(din, in, sizeof(int)*ARRAY_SIZE, cudaMemcpyHostToDevice);
    my_kernel<<<NUM_BLOCK, NUM_T_IN_B>>>(din, dout);
    cudaMemcpy(out, dout, sizeof(int)*ARRAY_SIZE, cudaMemcpyDeviceToHost);
    end = clock();
    
    printf("NULL_STREAM time >> %lf s\n\n", (double)(end-start) / CLOCKS_PER_SEC);

    cudaStream_t stream[NUM_STREAMS];

    for (int i = 0; i < NUM_STREAMS; i++)
        cudaStreamCreate(&stream[i]);

    int chunck_size = ARRAY_SIZE / NUM_STREAMS;
    
    start = clock();
    for (int i = 0; i < NUM_STREAMS; i++)
    {
        int offset = chunck_size * i;
        cudaMemcpyAsync(din + offset, in + offset, sizeof(int)*chunck_size, cudaMemcpyHostToDevice, stream[i]);
        my_kernel<<<NUM_BLOCK / NUM_STREAMS, NUM_T_IN_B, 0, stream[i]>>>(din + offset, dout + offset);
        cudaMemcpyAsync(out + offset, dout + offset, sizeof(int)*chunck_size, cudaMemcpyDeviceToHost, stream[i]);
    }    
    
    cudaDeviceSynchronize();
    end = clock();

    printf("NON_NULL_STREAM time >> %lf s\n\n", (double)(end-start) / CLOCKS_PER_SEC);

    for (int i = 0; i < NUM_STREAMS; i++)
        cudaStreamDestroy(stream[i]);
    
    cudaFree(din);
    cudaFree(dout);
    
    cudaFreeHost(in);
    cudaFreeHost(out);

    return 0;
}