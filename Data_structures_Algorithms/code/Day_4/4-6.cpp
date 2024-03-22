//스택 풀기

#include <iostream>

using namespace std;

int Divide(int a, int b);

int main(void)
{
    int a, b;
    cout << "두 개의 정수 입력: ";
    cin >> a >> b;

    try
    {
        cout << "a / b = " << Divide(a, b) << endl; 
    }
    catch(int exception)
    {
        cout << "입력 오류 : " << exception << endl;
        cout << "다시 실행하세요!!!" << endl; 
    }
    
    return 0;
}

int Divide(int a, int b)
{
    if (b == 0)
        throw b;
    
    return a / b;
}