#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    int id;
    char *name;
public:
    Person(int _id, char* _name)
    {
        id = _id;
        name = _name;   
    }
    Person(const Person& _p)    //생성자로 동적 할당을 하려면 반드시 깊은 복사를 사용해야함 (default)
    {
        id = _p.id;
        name = new char[strlen(_p.name) + 1];
        strcpy(name, _p.name);
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
    Person a(p);

    p.showData();
    a.showData();
    return 0;
}