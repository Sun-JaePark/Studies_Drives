// 포인터와 참조 기본

#include <iostream>

using namespace std;

int main(void)
{
    int a = 10;
    int *pa = &a;   // 4byte(32) 8byte(64) * 주소값 부여
    int &ra = a;    // & 값 부여

    cout << "a : " << a << endl;
    cout << "*pa : " << *pa << endl;
    cout << "&ra : " << ra << endl;

    return 0;
}