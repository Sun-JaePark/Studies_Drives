// struct

#include <iostream>

using namespace std;

struct Score_Struct
{
    char name[12];
    int kor, eng, math, tot;
    float avg;
};

int main(void)
{
    Score_Struct temp;

    cout << "이름 : ";  cin >> temp.name;
    cout << "국어 : ";  cin >> temp.kor;
    cout << "수학 : ";  cin >> temp.math;
    cout << "영어 : ";  cin >> temp.eng;

    temp.tot = temp.kor + temp.math + temp.eng;
    temp.avg = (float) temp.tot / 3;
    
    cout << endl << "### 출력결과 ###" << endl;
    cout << "name : " << temp.name << endl;
    cout << "kor : " << temp.kor << endl;
    cout << "math : " << temp.math << endl;
    cout << "eng : " << temp.eng << endl;
    cout << "total : " << temp.tot << endl;
    cout << "avg : " << temp.avg << endl;


    return 0;
}