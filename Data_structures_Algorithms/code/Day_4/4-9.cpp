//함수 템플릿

#include <iostream>

using namespace std;

template <typename T>
T Add(T a, T b)
{
    return a + b;
} 

int main(void)
{
    cout << Add(10, 20) << endl;            // 정수형으로 인식
    cout << Add(10.5, 20.5) << endl;        // 실수형으로 인식

    return 0;
}