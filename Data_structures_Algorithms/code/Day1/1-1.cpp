#include <iostream>

using namespace std;


void Func()
{
    for (int i = 1; i <= 100; i++)
    {
        cout << i << " ";
        if(i % 10 == 0)
            cout << endl;
    }
}

int main(void)
{
    Func();
    return 0;
}