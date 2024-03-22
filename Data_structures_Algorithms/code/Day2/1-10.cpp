// namespace 중첩

#include <iostream>

using namespace std;

namespace Park
{
    namespace Sun
    {
        int a = 10;
    }

    namespace Jae
    {
        int a = 20;
    }
}

int main(void)
{
    cout << "Park::Sun::a : " << Park::Sun::a << endl;
    cout << "Park::Jae::a : " << Park::Jae::a << endl;

    return 0;
}