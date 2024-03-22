#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    void setX(int _x){ x = _x; }        // this -> x
    void setY(int _y){ y = _y; }        // this -> y
    int getX(){ return x; }
    int getY(){ return y; }

    void showData()
    {
        cout << "x vector : " << x << endl;
        cout << "y vector : " << y << endl;
    }

    Point(int _x, int _y){};
};

int main(void)
{
    Point p;

    int t_x;
    int t_y;

    cout << "X vector input : ";
    cin >> t_x;

    cout << "Y vector input : ";
    cin >> t_y;

    p.setX(t_x);
    p.setY(t_y);

    cout << endl << "temp.x : " << p.getX() << endl;
    cout << "temp.y : " << p.getY() << endl;

    p.showData();

    return 0;
}