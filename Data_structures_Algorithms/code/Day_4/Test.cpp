//cin, cout, endl 내부 구현

#include <iostream>
#include <cstdio>

namespace mystd
{
    const char *endll = "\n";

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

    class istream
    {
        
    public:
        istream& operator>>(char *str)
        {
            scanf("%s", str, sizeof(*str));
            return *this;
        }
        istream& operator>>(int& i)
        {
            scanf("%d", &i);
            return *this;
        }
        istream& operator>>(double& d)
        {
            scanf("%lf", &d);
            return *this;
        }
    };
    ostream cout;
    istream cin;
}
using namespace mystd;

int main(void)
{
    int x = 0;
    double y = .0;
    char z[1024];
    
    cout << "문자열 : ";
    cin >> z;

    cout << "정 수 : ";
    cin >> x;

    cout << "실 수 : ";
    cin >> y;
    cout << _endll;

    cout << z << x << y << endll;
    return 0;
}