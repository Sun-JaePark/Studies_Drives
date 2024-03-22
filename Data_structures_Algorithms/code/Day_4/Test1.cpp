#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class AccountClass
{
private:
    const u_int MAX_MONEY = 100000;

    string account_id;
    string password;
    u_int want_money;

public:

    AccountClass(const string& _account_id, const string& _password)
    {
        account_id = _account_id;
        password = _password;
        want_money = 0;
    }

    ~AccountClass(void)
    {
        account_id = "";
        password = "";
        want_money = 0;
    }

    void ShowAccount(void)
    {
        cout << endl << "다음 입력을 다시 한 번 확인하세요!!!" << endl;
        cout << "계좌 번호 : " << account_id << endl;
        cout << "패스워드 : " << password << endl << endl;
    }

    void Show_Error_Money(void)
    {
        cout << endl << "현재 잔액: " << MAX_MONEY << endl;
        cout << "출금 희망액: " << want_money << "가 너무 많네요." << endl;
        want_money = 0;
    }

    void Show_Money(void)
    {
        cout << endl << "출금: " << want_money << " 잔액: " << MAX_MONEY -  want_money << endl;
    }

    void CheckPassword(void)
    {
        string temp = account_id;
        temp.erase(remove(temp.begin(), temp.end(), '-'), temp.end());
        if(temp.find(password) == string::npos) { throw password; }
    }

    void CheckMoney(const int& _want_money)
    {
        want_money = _want_money;
        if(MAX_MONEY < want_money) { throw want_money; }
    }
};




int main(void)
{

    string account_id = "";
    string password = "";

    u_int want_money = 0;

    bool account_loop_flag = false;
    bool money_loop_flag = false;


    while (!account_loop_flag)
    {   
        cout << "계좌 번호: "; cin >> account_id;
        cout << "비밀번호: "; cin >> password;

        AccountClass ac(account_id, password);
        
        try
        {
            ac.CheckPassword();
            while (!money_loop_flag)
            {
                cout << endl << "출금액: "; cin >> want_money;
                try
                {
                    ac.CheckMoney(want_money);
                    money_loop_flag = true;
                }
                catch(const u_int& int_except)
                {
                    ac.Show_Error_Money();
                    money_loop_flag = false;
                }
                
            }
            
            ac.Show_Money();
            account_loop_flag = true;

        }
        catch(const string& str_except)
        {
            ac.ShowAccount();
            ac.~AccountClass();

            account_loop_flag = false;
            money_loop_flag = false;
        }
        
    }
    
    

    return 0;
}