#include <iostream>

using namespace std;

class SuperClass
{
public:
    void show(void)
    {
        cout << "Super Class !!!" << endl;
    }
};

class BaseClass01: virtual public SuperClass
{
public:
    void show01(void)
    {
        cout << "Base Class #1 !!!" << endl;
    }
};

class BaseClass02: virtual public SuperClass
{
public:
    void show02(void)
    {
        cout << "Base Class #2 !!!" << endl;
    }
};

class DerivedClass : public BaseClass01, public BaseClass02
{
public:
    void showDerivedClass(void)
    {
        cout << "Derived Class !!!" << endl;
        show();
        show01();
        show02();
    }
};


int main(void)
{
    DerivedClass d;
    d.showDerivedClass();
    return 0;
}