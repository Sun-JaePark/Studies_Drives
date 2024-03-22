// 클래스 일반화

#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
    T data;
public:
    Data(T num) { data = num; }
    void setData(T num) { data = num; }
    T getData(void) { return data; } 
};

int main(void)
{
    Data<int> temp(10);
    cout << "temp: " << temp.getData() << endl;

    temp.setData(20);
    cout << "temp: " << temp.getData() << endl;
    return 0;
}