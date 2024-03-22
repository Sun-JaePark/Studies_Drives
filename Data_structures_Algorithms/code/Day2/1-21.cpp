//main 함수 메모리 주소 출력 => 함수 이름 자체가 포인터기 때문에 메모리 할당(Heap)

#include <iostream>

using namespace std;


void check()
{
    cout << "aaaaaaaaaaa" << endl;
}

int main(void)
{
    check();
    cout << &main << endl;
    cout << &check << endl;
    return 0;
}