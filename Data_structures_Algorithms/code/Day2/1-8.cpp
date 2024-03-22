// namespace가 다르면 함수 이름 중복 가능

#include <iostream>

using namespace std;

//namespace 나누면 같은 함수 이름 사용 가능

namespace A{
    void OUTPUT(void)
    {
        cout << "Hello World!!!" << endl;
        return;
    }
}

namespace B{
    void OUTPUT(void)
    {
        cout << "Hi Park!!!" << endl;
        return;
    }
}

int main(void)
{
    A::OUTPUT();
    B::OUTPUT();

    return 0 ;
}