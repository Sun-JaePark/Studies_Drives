// operator class++

#include <iostream>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);
    void showPosition(void);
    Point& operator++()     //++Point;
    {
        ++x;
        ++y;
        return *this;
    }
    Point& operator++(int)  //Point++; 
    {
        ++x;
        ++y;
        return *this;
    }

};

Point::Point(int x, int y)
{
    this -> x = x;
    this -> y = y;
}

void Point::showPosition(void)
{
    cout << "(" << x << ", " << y << ")" << endl;
}

int main(void)
{
    Point a(10, 20);
    cout << "a: ";
    a.showPosition();

    ++a;
    cout << "++a --> a: ";
    a.showPosition();

    a++;
    cout << "a++ --> a: ";
    a.showPosition();

    return 0;
}