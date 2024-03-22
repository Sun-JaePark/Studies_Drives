#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int Trapezodial_Serial(const double a, const double b, const int n, const double h);
int Trapezodial_ImplicitBarrier(const double a, const double b, const int n, const double h);
int Trapezodial_ImplicitBarrier_NoSync(const double a, const double b, const int n, const double h);
int Trapezodial_ImplicitBarrier_SharedLocalVar(const double a, const double b, const int n, const double h);

int Trapezodial_Atomic(const double a, const double b, const int n, const double h);
int Trapezodial_Critical(const double a, const double b, const int n, const double h);
int Trapezodial_Locking(const double a, const double b, const int n, const double h);
int Trapezodial_Reduction(const double a, const double b, const int n, const double h);

int main(int argc, char* argv[])
{

    return 0;
}