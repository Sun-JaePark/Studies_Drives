#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define IS_LOCK 0

int Sleep(const double& _dly);

int main(int argc, char* argv[])
{
    int buf = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);
    bool is_Fin = false;
    int numProduce = strtol(argv[1], NULL, 10);
    double delay = strtod(argv[2], NULL);

    #pragma omp parallel sections shared(is_Fin, lock) num_threads(2)
    {
        #pragma omp section
        {
            while(numProduce > 0)
            {
#if IS_LOCK
                omp_set_lock(&lock);
#endif
                if(!buf)
                {
                    buf = numProduce;
                    printf("Produce push %d\n", buf);
                    numProduce--;
                }
#if IS_LOCK
                omp_unset_lock(&lock);
#endif
                Sleep(delay);
            }
            is_Fin = true;
        }

        #pragma omp section
        {
            int get = 0;
            while(!is_Fin)
            {
#if IS_LOCK
                omp_set_lock(&lock);
#endif
                if(buf > 0)
                {
                    get = buf;
                    buf = 0;
                    printf("Consumer get %d\n", get);
                }
#if IS_LOCK
                omp_unset_lock(&lock);
#endif
                Sleep(delay);
            }
        }
    }
    omp_destroy_lock(&lock);
    printf("Finished!\n");

    return 0;
}

int Sleep(const double& _dly)
{
    clock_t s_clk = clock();
    while((double)((clock() - s_clk)/CLOCKS_PER_SEC) < _dly){}
    return 1;
}