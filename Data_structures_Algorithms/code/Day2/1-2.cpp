// cstring 

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
    char str[] = "Hi~ Park!!!";
    char copy[1024];
    int len = strlen(str);

    strcpy(copy, str);

    cout << "길이 : " << len << endl;
    cout << "str : " << str << endl;
    cout << "copy : " << copy << endl;

    return 0;
}