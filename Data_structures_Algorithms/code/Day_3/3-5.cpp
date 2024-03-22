// 얕은 복사

#include <iostream>

using namespace std;

class Person
{
private:
    int id;
    char* name;
public:
    Person(int _id, char* _name)
    {
        id = _id;
        name = _name;   //생성자로 동적 할당을 하려면 반드시 깊은 복사를 사용해야함
    }
    ~Person(void){}
    void showData(void)
    {
        cout << "x: " << id << ", y: " << name << endl;
    }
};

int main(void)
{
    Person p(1000, "Sunsun");
    Person b = p;   //생성자로 동적 할당을 하려면 반드시 깊은 복사를 사용해야함
    Person a(b);    //생성자로 동적 할당을 하려면 반드시 깊은 복사를 사용해야함
    p.showData();
    b.showData();
    a.showData();
    return 0;
}