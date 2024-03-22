//c++ 캐스팅 

#include <iostream>

using namespace std;


int main(void)
{
    // int a, b = 1;

    // cout << a << b << endl;

    int i;
    double d = 3.14159;

    i = int(d);     //(int)d

    cout << "i : " << i << endl;
    cout << "d : " << d << endl;

    return 0;
}