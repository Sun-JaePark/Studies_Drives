// operator in class

#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0);
    void ShowPosition();
    Point operator+(int _num);
    friend Point operator+(int _num, Point& _p);
};

Point::Point(int x, int y)
{
    this -> x = x;
    this -> y = y;
}

void Point::ShowPosition()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

Point Point::operator+(int num)
{
    cout << "222" << endl;
    Point temp(x + num, y + num);
    return temp;
}
Point operator+(int num, Point& p)
{
    cout << "111" << endl;
    return p + num;
}

int main(void)
{
    Point p1(10, 20);
    cout << "p1 : "; 
    p1.ShowPosition();

    Point p2 = p1 + 10;
    cout <<  endl << "p1 + 10 " << endl;
    cout << "p2 : "; 
    p2.ShowPosition();

    p2 = 10 + p1;
    cout <<  endl << "p1 + 10 " << endl;
    cout << "p2 : "; 
    p2.ShowPosition();

    return 0;
}