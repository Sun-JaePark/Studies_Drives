// 다중 상속

#include <iostream>

using namespace std;

class SuperClass
{
public:
    void Show(){ cout << "Super Class!!!" << endl; }
};

class BaseClass
{
public:
    void Show(){ cout << "Base Class!!!" << endl; }
};

class DerivedClass : public SuperClass, public BaseClass
{
public:
    void Show_DerivedClass()
    { 
        cout << "Derived Class!!!" << endl;
        SuperClass::Show();
        BaseClass::Show();
    }
};

int main(void)
{
    DerivedClass de;
    de.Show_DerivedClass();
    return 0;
}