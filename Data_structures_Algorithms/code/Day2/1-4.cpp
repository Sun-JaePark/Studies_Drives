// Func overloading

#include <iostream>

using namespace std;

int ADD(int, int);
double ADD(double, double);

int main(void)
{
    cout << ADD(10, 20) << endl;
    cout << ADD(10.5, 20.5) << endl;

    return 0;
}

int ADD(int _a, int _b)
{
    return a + b;
}
    

double ADD(double _a, double _b)
{
    return a + b;
}
    
