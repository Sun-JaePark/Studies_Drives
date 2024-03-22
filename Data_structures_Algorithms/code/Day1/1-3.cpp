#include <iostream>

using namespace std;

void Func(u_int& _result)
{
    u_int cur_i = 1;
    u_int before_i = 1;
    u_int next_temp = 0;
    for (int i = 3; i <= 15; i++)
    {
        next_temp = before_i + cur_i;
        _result += next_temp;
        before_i = cur_i;
        cur_i = next_temp;
    }
}

int main(void)
{
    u_int result = 2;
    Func(result);
    cout << result << endl;
    return 0;
}