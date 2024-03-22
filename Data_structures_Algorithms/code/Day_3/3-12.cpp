// 상속, virtual

#include <iostream>

using namespace std;

class BaseClass
{
public:
    void Show(void)
    {
        cout << "BaseClass!!!" << endl;
    }
    virtual void Show_1(void)
    {
        cout << "BaseClass_1!!!" << endl;
    }
    virtual void Show_2(void)
    {
        cout << "BaseClass_2!!!" << endl;
    }

    //virtual void Show_3(void) = 0;      // 순수 가상함수 (함수 정의 x) --> 객체 생성 못함 (중요)
};

class DerivedClass : public BaseClass
{   
public:
    void Show(void)
    {
        cout << "DerivedClass!!!" << endl;
    }

    void Show_1(void)                       //virtual overloding
    {
        cout << "DerivedClass_1!!!" << endl;
    }

    void Show_2(void)
    {
        BaseClass::Show_2();
        cout << "DerivedClass_2!!!" << endl;
    }

    void Show_3(void)
    {
        cout << "DerivedClass_3!!!" << endl;
    }

};

int main(void)
{
    BaseClass *base = new BaseClass;
    DerivedClass *derived = new DerivedClass;

    base -> Show();
    base -> Show_1();
    base -> Show_2();

    derived -> Show();
    derived -> Show_1();
    derived -> Show_2();
    derived -> Show_3();

    return 0;
}