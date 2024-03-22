#include <iostream>
#include <omp.h>
#include <ctime>

#define IS_BAR 1

int Sleep(const double& _time);

int main(int argc, char* argv[])
{
    double sleep_t = strtod(argv[1], NULL);
    int tID = 0;
    #pragma omp parallel private(tID)
    {
        tID = omp_get_thread_num();

        if(tID % 2 == 0)
            Sleep(sleep_t);
        printf("[%d] before\n", tID);
#if IS_BAR
        #pragma omp barrier
#endif
        printf("[%d] after\n", tID);
    }
    return 0;
}

int Sleep(const double& _time)
{
    time_t s_time = time(NULL);
    while(time(NULL) - s_time < _time) {};
    return 1;
}