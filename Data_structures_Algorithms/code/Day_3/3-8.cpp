// 포인터 접근 (주소값)

#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point *getThis(void)
    {
        return this;
    }

};

int main(void)
{
    Point *p = new Point();
    cout << "p: " << p << endl;
    cout << "this: " << p -> getThis() << endl;
    return 0;
}