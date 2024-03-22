// 상속 변수 접근

#include <iostream>

using namespace std;

class BaseClass
{
private:
    int a;
protected:
    int b;
public:
    int c;
};

class DerivedClass : public BaseClass
{
public:
    void setData(void)
    {
       //a = 10;        // 접근 불가
        b = 20;         // 접근 가능 protected
        c = 30;         // 접근 가능 public
        cout << b << endl;
    }
};

int main(void)
{
    BaseClass base;
    DerivedClass derived;

    //base.a = 10;  접근 불가
    //base.b = 20;  접근 불가
    //derived.a = 10; 접근 불가
    //derived.b = 20; 접근 불가
    derived.c = 30; //접근 가능

    return 0;
}