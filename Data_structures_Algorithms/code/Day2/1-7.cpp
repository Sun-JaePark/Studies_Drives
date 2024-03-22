// inline 함수 (namespace)

#include <iostream>

using namespace std;


inline int ADD(int, int);       //보통 namespace와 묶어서 씀

int main(void)
{
    int sum;
    sum = ADD(15, 20);
    cout << sum << endl;

    return 0;
}

inline int ADD(int _a, int _b)
{
    return _a + _b;
}
