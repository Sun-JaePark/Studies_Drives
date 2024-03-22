//서로 다른 자료형

#include <iostream>

using namespace std;

template <typename T1, typename T2>
void ShowData(T1 a, T2 b)
{
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

int main(void)
{
    ShowData(10, 20);
    ShowData(10, 10.5);
    return 0;
}