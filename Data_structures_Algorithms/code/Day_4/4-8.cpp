// 예외 클래스와 객체

#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    string id;
    string pass;

public:
    User(string id, string pass)
    {
        this -> id = id;
        this -> pass = pass;
    }

    void ShowUser(void)
    {
        cout << "ID : " << this -> id << endl;
        cout << "PASSWORD : " << this -> pass << endl;
    }
};

int main(void)
{
    const string ID = "sun";
    const string PASS = "sun1";

    string user_id;
    string user_pass;

    cout << "input ID : ";
    cin >> user_id;
    cout << "input PASSWORD : ";
    cin >> user_pass;

    User user(user_id, user_pass);
    try
    {
        if(ID != user_id || PASS != user_pass)
            throw User(user_id, user_pass);
    }
    catch(User& e)
    {
        e.ShowUser();
    }
    
    return 0;
}