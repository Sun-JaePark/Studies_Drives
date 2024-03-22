// 참조형 이해

#include <iostream>

using namespace std;

int main(void)
{
    int a = 10;
    int &ra = a;

    a++;

    cout << "a : " << a << endl;
    cout << "ra : " << ra << endl;

    ra++;

    cout << "a : " << a << endl;
    cout << "ra : " << ra << endl;
    return 0;
}