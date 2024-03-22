#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    int getX(){ return x; }
    int getY(){ return y; }

    void showData()
    {
        cout << "x vector : " << x << endl;
        cout << "y vector : " << y << endl;
    }

    Point(int x, int y)
    { 
        this -> x = x;
        this -> y = y; 
    }
};

int main(void)
{

    int t_x;
    int t_y;

    cout << "X vector input : ";
    cin >> t_x;

    cout << "Y vector input : ";
    cin >> t_y;

    Point p(t_x, t_y);

    cout << endl << "temp.x : " << p.getX() << endl;
    cout << "temp.y : " << p.getY() << endl;

    p.showData();

    return 0;
}