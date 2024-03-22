#include <cuda_tid.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM_BLOCK (128 * 1024)
#define NUM_T_IN_B 1024
#define ARRAY_SIZE (NUM_T_IN_B * NUM_BLOCK)

#define NUM_STREAMS 2

__global__ void my_kernel(int* _input, int* _output)
{
    int index = GRID_1D_BLOCK_1D_TID;

    int temp = 0;
    for (int i = 0; i < 250; i++)
        temp = (temp + _input[index] * 5) % 10;

    _output[index] = temp;
}

int main(void)
{
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

    cudaStream_t stream[NUM_STREAMS];
    cudaEvent_t start[NUM_STREAMS];
    cudaEvent_t end[NUM_STREAMS];

    for (int i = 0; i < NUM_STREAMS; i++)
    {
        cudaStreamCreate(&stream[i]);
        cudaEventCreate(&start[i]);
        cudaEventCreate(&end[i]);
    }

    int chunck_size = ARRAY_SIZE / NUM_STREAMS;
    
    for (int i = 0; i < NUM_STREAMS; i++)
    {
        int offset = chunck_size * i;
        cudaEventRecord(start[i], stream[i]);
        cudaMemcpyAsync(din + offset, in + offset, sizeof(int)*chunck_size, cudaMemcpyHostToDevice, stream[i]);
        my_kernel<<<NUM_BLOCK / NUM_STREAMS, NUM_T_IN_B, 0, stream[i]>>>(din + offset, dout + offset);
        cudaMemcpyAsync(out + offset, dout + offset, sizeof(int)*chunck_size, cudaMemcpyDeviceToHost, stream[i]);
        cudaEventRecord(end[i], stream[i]);
    }    
    
    cudaDeviceSynchronize();

    for (int i = 0; i < NUM_STREAMS; i++)
    {
        float time = .0f;
        cudaEventElapsedTime(&time, start[i], end[i]);
        printf("Stream[%d] Time >> %f ms\n", i, time);
    }

    for (int i = 0; i < NUM_STREAMS; i++)
    {
        cudaStreamDestroy(stream[i]);
        cudaEventDestroy(start[i]);
        cudaEventDestroy(end[i]);
    }
    
    cudaFree(din);
    cudaFree(dout);
    
    cudaFreeHost(in);
    cudaFreeHost(out);

    return 0;
}