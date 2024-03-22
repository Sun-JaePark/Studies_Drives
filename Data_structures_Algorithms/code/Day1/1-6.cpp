#include <iostream>
#include <array>

using namespace std;

void Func(u_int& _max_value)
{
    array<u_int, 6> numList;

    for (int i = 0; i < numList.size(); i++)
        cin >> numList[i];
    
    
    for (int i = 0; i < numList.size(); i++)
    {
        if (numList[i] > _max_value)
            _max_value = numList[i];
    }
}

int main(void)
{
    u_int max_value = 0;
    Func(max_value);
    cout << max_value << endl;
    
    return 0;
}