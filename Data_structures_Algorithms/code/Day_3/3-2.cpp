// friend 선언

#include <iostream>

using namespace std;

class Count
{
private:
    int i;
    friend class fCount;    //fCount 내에 함수에 사용하는 Count 변수의 접근 권한 부여
public:
    Count(){ i  = 0; }
    void showData(void)
    {
        cout << "i: " << i << endl;
    }
    friend void setCount1(Count&, int); //setCount1 함수에 사용하는 Count 변수의 접근 권한 부여
};

class fCount
{
public:
    void setCount(Count& _r, int _num)
    {
        _r.i = _num;
    }
};

void setCount1(Count& _r, int _num)
{
    _r.i = _num;
}

int main(void)
{
    Count cc;
    fCount fc;

    fc.setCount(cc, 10);
    cc.showData();

    setCount1(cc, 20);
    cc.showData();
    return 0;
}