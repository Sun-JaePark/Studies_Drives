// 생성자와 디폴트 매개 변수

#include <iostream>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    void showData(void)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }

};

int main(void)
{
    Point a; // 0 0
    a.showData();

    Point b(10, 20);
    b.showData();

    return 0;
}
