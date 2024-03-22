//생성자와 함수 다중 정의

#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(){}  //default
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    
    ~Point(){} //default

    void showData(void)
    {
        cout << "x: " << x << ", y: " << y << endl;
    }

};


int main(void)
{
    Point a;
    Point b(10, 20);

    a.showData();       //trash value
    b.showData();

    return 0;
}