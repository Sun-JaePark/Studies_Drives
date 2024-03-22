// 하나의 try 블록과 여러 개의 catch 블록

#include <iostream>

using namespace std;

int main(void)
{
    int num;

    cout << "정수 입력: ";
    cin >> num;

    try
    {
        if(num > 0) throw 1;
        else throw 'e';
    }
    catch(int exception)
    {
        cout << "int형 예외 발생: " << exception << endl;
    }
    catch(char exception)
    {
        cout << "char형 예외 발생: " << exception << endl;
    }
    
    return 0;
}