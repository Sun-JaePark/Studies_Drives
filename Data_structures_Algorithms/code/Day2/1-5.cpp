// Func 매개변수 default 초기화

#include <iostream>

using namespace std;

int ADD(int, int = 0);

int main(void)
{
    cout << ADD(10) << endl;
    cout << ADD(10, 20) << endl;
    return 0;
}

int ADD(int _a, int _b)
{
    return _a + _b;
}