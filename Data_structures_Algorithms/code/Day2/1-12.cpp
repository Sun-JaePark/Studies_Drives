// 외부 소스 extern으로 접근(전역 데이터에 대해)

#include <iostream>

using namespace std;

extern void OUTPUT(void);   // 가능

//extern int temp;    // 1-11 에서 namespace에 묶여 있기 때문에 extern으로 접근 불가

extern int temp1;

int main(void)
{
    //cout << "temp : " << temp << endl;
    cout << "temp1 : " << temp1 << endl;
    OUTPUT();
    return 0;
}