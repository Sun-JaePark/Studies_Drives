// 매크로 상수 (함수 정의)

#include <iostream>
#define ADD(a, b) ((a) + (b))

using namespace std;

int main(void)
{
    int sum;

    sum = ADD(10, 20);
    sum = (30) + (20);
    cout << sum << endl;
    
    return 0;
}