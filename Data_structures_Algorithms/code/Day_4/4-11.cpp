//함수 템플릿의 특수화

#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
int sizeOf_1(T data)
{
    return sizeof(T);
}

// template<>
// int sizeOf_2(const char* data)
// {
//     return (int)strlen(data);
// }

int main(void)
{
    int i = 10;
    double d = 10.5;
    char str[20] = "Hi, Clickseo!!!";
    const char* pStr = "Hello World!!!";

    cout << sizeOf_1(i) << endl;
    cout << sizeOf_1(d) << endl;
    cout << sizeOf_1(str) << endl;
    cout << sizeOf_1(pStr) << endl;
    
    return 0;
}