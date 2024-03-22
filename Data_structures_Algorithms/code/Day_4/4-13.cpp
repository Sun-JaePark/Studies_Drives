// 클래스 일반화

#include <iostream>

using namespace std;

template <typename T>
class Data
{
private:
    T data;
public:
    Data(T num);
    void setData(T num);
    T getData(void);
};

template<typename T>
Data<T>::Data(T num) { data = num; }

template<typename T>
void Data<T>::setData(T num) { data = num; }

template<typename T>
T Data<T>::getData() { return data; }

int main(void)
{
    Data<int> a(0);
    cout << "a: " << a.getData() << endl;

    a.setData(10);
    cout << "a: " << a.getData() << endl;

    Data<char> b('A');
    cout << "b: " << b.getData() << endl;

    return 0;
}