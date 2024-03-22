#include <iostream>

using namespace std;

template <typename T1, typename T2>
void printArr(const T1& _pArr, const T2& _num)
{
    for (int i = 0; i < _num; i++)
        cout << *(_pArr + i) << " ";
    
    cout << endl;
    
}
int main(void)
{
    double d_data_start = 0.5;
    int i_data_start = 0;

    char cArr[] = "Hi~Clickseo";
    u_int iArr[5];
    double dArr[5];

    int cArrlen = sizeof(cArr) / sizeof(char);
    int iArrlen = sizeof(iArr) / sizeof(int);
    int dArrlen = sizeof(dArr) / sizeof(double);

    for (int i = 0; i < iArrlen; i++)
    {
        i_data_start += 10; 
        *(iArr + i) = i_data_start;
    }
    for (int i = 0; i < dArrlen; i++)
    {
        d_data_start += 10; 
        *(dArr + i) = d_data_start;
    } 
    
    printArr(cArr, cArrlen);
    printArr(iArr, iArrlen);
    printArr(dArr, dArrlen);

    return 0;
}