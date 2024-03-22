// 클래스 멤버 접근

#include <iostream>

using namespace std;

class Point
{
public:
    int x;
    int y;
    void OutPut(void);
};

//멤버 함수 : 클래스 외부 정의
void Point::OutPut(void)
{
    cout << "x: " << x << ", y: " << y << endl;
}

int main(void)
{
    Point a;
    a.x = 10;
    a.y = 20;
    a.OutPut();

    //Point b(a); // 복사 생성자
    Point b = a;
    b.OutPut();
    
    return 0;
}