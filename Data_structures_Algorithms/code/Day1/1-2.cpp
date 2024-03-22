#include <iostream>

using namespace std;


void Func(u_int& _result)
{
    for (int i = 0; i <= 10; i++)
    {
        _result += i;
    }
}
int main(void)
{
    u_int result = 0;
    Func(result);
    cout << result << endl;
    return 0;
}