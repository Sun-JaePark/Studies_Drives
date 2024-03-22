#include <iostream>

using namespace std;

void Swap(int &, int &);

int main(void)
{
    int a = 10, b = 20;

    cout << "a : " << a << " , b : " << b << endl;
    Swap(a, b);
    cout << "a : " << a << " , b : " << b << endl;

    return 0;
}

void Swap(int &_ra, int &_rb)
{
    int temp;
    temp = _ra;
    _ra = _rb;
    _rb = temp;
}