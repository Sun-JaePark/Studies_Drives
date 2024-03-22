// 1-12와 연결됨 (extern)

#include <iostream>

using namespace std;

namespace
{
    int temp = 10; // => static 키워드를 사용한 전역 변수나 함수를 정의한 경우와 동일
}

int temp1 = 1;  // => static으로 선언한 전역변수 extern으로 접근 불가

void OUTPUT()
{
    cout << "temp : " << temp << endl;
    return;
}