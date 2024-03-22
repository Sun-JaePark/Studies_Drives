#include <iostream>
#include <string>

using namespace std;

void Func(string& _grade)
{
    u_int num = 0;
    cin >> num;
    if(num >= 70)
        _grade = "pass";
    else
        _grade = "nonpass";
    
}

int main(void)
{
    string grade = "";
    Func(grade);
    cout << grade << endl;
    return 0;
}