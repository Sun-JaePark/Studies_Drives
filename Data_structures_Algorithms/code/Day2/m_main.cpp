// namspace 분할 구현 묶기

#include <iostream>

using namespace std;

namespace A { void OutPut(void); }
namespace B { void OutPut(void); }기

int main(void)
{
    A::OutPut();
    B::OutPut();
    return 0;
}