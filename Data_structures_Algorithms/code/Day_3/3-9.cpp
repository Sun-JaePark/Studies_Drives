//this 접근자, delete

#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(){ x = y = 0; }
    Point(int x, int y = 0)
    {
        this -> x = x;
        this -> y = y;
    }
    Point(const Point& p)
    {
        this -> x = p.x;
        this -> y = p.y;
    }
    void showData(void)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }
};


int main(void)
{
    Point* pArr[3];

    pArr[0] = new Point();
    pArr[1] = new Point(10, 20);
    pArr[2] = new Point(*pArr[1]);

    for (int i = 0; i < 3; i++)
        pArr[i] -> showData();

    for (int i = 0; i < 3; i++)
        delete pArr[i];

    return 0;
}