// 지역 변수 및 전역 변수

#include <iostream>

using std::cout;
using std::endl;

int temp = 0;

int main(void)
{
    int temp = 10;

    ::temp++;

    cout << "지역 변수 : " << temp << endl;
    cout << "전역 변수 : " << ::temp << endl;

    return 0;
}