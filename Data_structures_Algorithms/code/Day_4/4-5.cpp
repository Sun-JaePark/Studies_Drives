//0으로 정수 나누기 예외처리

#include <iostream>

using namespace std;

int main(void)
{
    int a, b;

    cout << "두 개의 정수 입력: ";
    cin >> a >> b;

    try
    {
        if (b == 0)
            throw b;
        
        cout << "a / b = " << a / b << endl;
        cout << "a % b = " << a % b << endl;
        
    }
    catch(int excepction)
    {
        cout << "입력오류: " << excepction << endl;
        cout << "다시 실행하세요!!!" << endl;
    }
    
    return 0;
}