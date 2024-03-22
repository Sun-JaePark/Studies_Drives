// 포인터 접근

#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    void showData(void)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main(void)
{
    Point a;
    Point *p = &a;

    a.showData();

    (*p).showData();
    p -> showData();

    return 0;
}