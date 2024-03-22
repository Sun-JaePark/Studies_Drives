//cin, cout, endl 내부 구현

#include <iostream>
#include <cstdio>

namespace mystd
{
    char *endl = "\n";

    class ostream
    {
    public:
        ostream& operator<<(char *str)
        {
            printf(" %s ", str);
            return *this;
        }
        ostream& operator<<(int n)
        {
            printf(" %d ", n);
            return *this;
        }
        ostream& operator<<(double d)
        {
            printf(" %f ", d);
            return *this;
        }
    };
    ostream cout;
}
using namespace mystd;

int main(void)
{
    cout << "Park" << endl;
    cout << 100 << endl;
    cout << 3.14159 << endl;

    cout << "Park" << 100 << 3.14159 << endl;
    return 0;
}