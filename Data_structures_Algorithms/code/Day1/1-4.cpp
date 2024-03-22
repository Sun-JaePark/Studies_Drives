#include <iostream>

using namespace std;

void Func(u_int& _result)
{
    u_int fir = 0;
    u_int sec = 0;
    cin >> fir >> sec;
    _result = (fir + sec) * 0.5f;

}

int main(void)
{
    u_int result = 0;
    Func(result);
    cout << result << endl;

    return 0;
}