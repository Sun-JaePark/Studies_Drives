#include <cuda_tid.h>

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROW_SIZE 32
#define COL_SIZE 32
#define K_SIZE 128

#define WORK_LOAD 1024
#define MAT_SIZE_A (ROW_SIZE * K_SIZE)
#define MAT_SIZE_B (K_SIZE * COL_SIZE)
#define MAT_SIZE_C (ROW_SIZE * COL_SIZE)

#define memset_Zero(_p, _type, _size) memset(_p, 0, sizeof(_type) * _size)
#define dMem_Alloc(_p, _type, _size) cudaMalloc(&_p, sizeof(_type) * _size)

void gen_Input_Matrices(float (*_a_mat)[K_SIZE], float (*_b_mat)[COL_SIZE]);
bool check_result(float (*_host_c_mat)[COL_SIZE], float (*_device_c_mat)[COL_SIZE]);

#if (K_SIZE <= 128)
__global__ void matMul_kernel(float* _a_mat, float* _b_mat, float* _c_mat)
{
    int row = threadIdx.y;
    int col = threadIdx.x;
    int index = row * blockDim.x + col;

    _c_mat[index] = 0;
    
    for (int k = 0; k < K_SIZE; k++)
        for (int i = 0; i < WORK_LOAD; i++)
            _c_mat[index] += _a_mat[row * K_SIZE + k] * _b_mat[col + k * COL_SIZE];
}

__global__ void matMul_kernel_rowx(float* _a_mat, float* _b_mat, float* _c_mat)
{
    int row = threadIdx.x;
    int col = threadIdx.y;
    int index = row * blockDim.y + col;

    _c_mat[index] = 0;
    
    for (int k = 0; k < K_SIZE; k++)
        for (int i = 0; i < WORK_LOAD; i++)
            _c_mat[index] += _a_mat[row * K_SIZE + k] * _b_mat[col + k * COL_SIZE];
}

__global__ void matMul_kernel_shared(float* _a_mat, float* _b_mat, float* _c_mat)
{
    int row = threadIdx.y;
    int col = threadIdx.x;
    int index = row * blockDim.x + col;

    __shared__ float s_a[ROW_SIZE][K_SIZE];
    __shared__ float s_b[K_SIZE][COL_SIZE];

    for (int k = 0; k < K_SIZE; k++)
    {
        s_a[row][k] = _a_mat[row * K_SIZE + k];
        s_b[k][col] = _b_mat[col + k * COL_SIZE];
    }

    __syncthreads();

    _c_mat[index] = 0;
    for (int k = 0; k < K_SIZE; k++)
        for (int i = 0; i < WORK_LOAD; i++)
            _c_mat[index] += s_a[row][k] * s_b[k][col];
    
}
#endif

__global__ void matMul_kernel_register(float* _a_mat, float* _b_mat, float* _c_mat)
{
    int row = threadIdx.y;
    int col = threadIdx.x;
    int index = row * blockDim.x + col;

    float s_c = 0;
    
    for (int k = 0; k < K_SIZE; k++)
        for (int i = 0; i < WORK_LOAD; i++)
            s_c += _a_mat[row * K_SIZE + k] * _b_mat[col + k * COL_SIZE];

    _c_mat[index] = s_c;
}

__global__ void matMul_kernel_shared_c(float* _a_mat, float* _b_mat, float* _c_mat)
{
    int row = threadIdx.y;
    int col = threadIdx.x;
    int index = row * blockDim.x + col;

    __shared__ float s_c[MAT_SIZE_C];
    
    s_c[index] = 0;
    for (int k = 0; k < K_SIZE; k++)
        for (int i = 0; i < WORK_LOAD; i++)
            s_c[index] += _a_mat[row * K_SIZE + k] * _b_mat[col + k * COL_SIZE];
            
    _c_mat[index] = s_c[index];
}

int main(void)
{
    float a_mat[ROW_SIZE][K_SIZE] = { .0, };
    float b_mat[K_SIZE][COL_SIZE] = { .0, };
    float host_c_mat[ROW_SIZE][COL_SIZE] = { .0, };
    float device_c_mat[ROW_SIZE][COL_SIZE] = { .0, };

    float* da_mat = nullptr;
    float* db_mat = nullptr;
    float* dc_mat = nullptr;

    clock_t start_time = NULL;
    clock_t end_time = NULL;

    memset_Zero(a_mat, float, MAT_SIZE_A);
    memset_Zero(b_mat, float, MAT_SIZE_B);
    memset_Zero(host_c_mat, float, MAT_SIZE_C);
    memset_Zero(device_c_mat, float, MAT_SIZE_C);

    dMem_Alloc(da_mat, float, MAT_SIZE_A);
    dMem_Alloc(db_mat, float, MAT_SIZE_B);
    dMem_Alloc(dc_mat, float, MAT_SIZE_C);

    gen_Input_Matrices(a_mat, b_mat);

    start_time = clock();
    for(int r = 0; r < ROW_SIZE; r++)
        for(int c = 0; c < COL_SIZE; c++)
            for(int k = 0; k < K_SIZE; k++)
                for(int i = 0; i < WORK_LOAD; i++)
                host_c_mat[r][c] += a_mat[r][k] * b_mat[k][c];
    end_time = clock();
    printf("HOST_MULTIPLICATION >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    cudaMemcpy(da_mat, a_mat, sizeof(float) * MAT_SIZE_A, cudaMemcpyHostToDevice);
    cudaMemcpy(db_mat, b_mat, sizeof(float) * MAT_SIZE_B, cudaMemcpyHostToDevice);
    end_time = clock();
    printf("DATA TRANSFER (HOST -> DEVICE) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);

    dim3 block_dim(COL_SIZE, ROW_SIZE);
    dim3 block_dim_row_x(ROW_SIZE, COL_SIZE);
    dim3 grid_dim(1);
#if (K_SIZE <= 128)
    start_time = clock();
    matMul_kernel<<<grid_dim, block_dim>>>(da_mat, db_mat, dc_mat);
    cudaThreadSynchronize();
    end_time = clock();
    printf("KERNEL_MULTIPLICATION (GLOBAL) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    matMul_kernel_rowx<<<grid_dim, block_dim_row_x>>>(da_mat, db_mat, dc_mat);
    cudaThreadSynchronize();
    end_time = clock();
    printf("KERNEL_MULTIPLICATION (GLOBAL_ROW_X) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);
    
    start_time = clock();
    matMul_kernel_shared<<<grid_dim, block_dim>>>(da_mat, db_mat, dc_mat);
    cudaThreadSynchronize();
    end_time = clock();
    printf("KERNEL_MULTIPLICATION (SHARED) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);
#endif

    start_time = clock();
    matMul_kernel_register<<<grid_dim, block_dim>>>(da_mat, db_mat, dc_mat);
    cudaThreadSynchronize();
    end_time = clock();
    printf("KERNEL_MULTIPLICATION (REGISTER) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);


    start_time = clock();
    matMul_kernel_shared_c<<<grid_dim, block_dim>>>(da_mat, db_mat, dc_mat);
    cudaThreadSynchronize();
    end_time = clock();
    printf("KERNEL_MULTIPLICATION (SHARED_C) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);

    start_time = clock();
    cudaMemcpy(device_c_mat, dc_mat, sizeof(float) * MAT_SIZE_C, cudaMemcpyDeviceToHost);
    end_time = clock();
    printf("DATA TRANSFER (DEVICE -> HOST) >> %lf s\n", (double)(end_time-start_time) / CLOCKS_PER_SEC);

    if(!check_result(host_c_mat, device_c_mat)) printf("!!!!!!Result is not correct!!!!!!\n");
    else printf("!Result is correct!\n");

    return 0;
}

void gen_Input_Matrices(float (*_a_mat)[K_SIZE], float (*_b_mat)[COL_SIZE])
{
    for (int r = 0; r < ROW_SIZE; r++)
        for (int k = 0; k < K_SIZE; k++)
            _a_mat[r][k] = rand() % 100;

    for (int k = 0; k < K_SIZE; k++)
        for (int c = 0; c < COL_SIZE; c++)
            _b_mat[k][c] = rand() % 100;
}

bool check_result(float (*_host_c_mat)[COL_SIZE], float (*_device_c_mat)[COL_SIZE])
{
    bool is_correct = true;

    float* p_host_c = &_host_c_mat[0][0];
    float* p_device_c = &_device_c_mat[0][0];

    for (int i = 0; i < MAT_SIZE_C; i++)
    {
        if (p_host_c[i] != p_device_c[i])
        {
            printf("[%d] %.2f, %.2f\n", i, p_host_c[i], p_device_c[i]);
            is_correct = false;
            break;
        }
    }
    
    return is_correct;
}