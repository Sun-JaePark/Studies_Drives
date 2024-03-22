//객체 포인터와 참조 (계층 구조)

#include <iostream>

using namespace std;

class Person
{
public:
    void sleep(void)
    {
        cout << "Sleep!!!" << endl;
    }
};

class Student : public Person
{
public:
    void study(void)
    {
        cout << "Study!!!" << endl;
    }
};

class PartTimeStudent : public Student
{
public:
    void work(void)
    {
        cout << "Work!!!" << endl;
    }
};

int main(void)
{
    Person* pPerson = new Person;
    Person* pStudent = new Student;
    Person* pPartTimeStudent = new PartTimeStudent;

    pPerson -> sleep();
    pStudent -> sleep();
    pPartTimeStudent -> sleep();

    //pStudent -> study();    // new Student로 선언했기때문에 접근 불가
    //pStudent -> work();    // new PartTimeStudent로 선언했기때문에 접근 불가 
    
    PartTimeStudent aPTS;
    Person& rPersonB = aPTS;
    Student& rStudentB = aPTS;
    PartTimeStudent& rPartTimeStudentB = aPTS;

    Person  bPTS;
    Person& rPersonA = bPTS;

    //Student& rStudentA = bPTS;    // 선언은 하위 게층이지만 대입을 상위 계층을 해서 접근 불가
    //PartTimeStudent& rPartTimeStudent = bPTS;   // 선언은 하위 게층이지만 대입을 상위 계층을 해서 접근 불가

    return 0;
}