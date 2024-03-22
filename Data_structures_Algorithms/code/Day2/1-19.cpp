#include <iostream>

#include <stdlib.h>     // 메모리 할당 : malloc, calloc, realloc // 메모리 해제 : free

using namespace std;

struct Score_Struct
{
    char name[12];
    int kor, eng, math, tot;
    float avg;
};

void OutPut(Score_Struct);


int main(void)
{
    Score_Struct data = { "박선재", 70, 80, 90, 240, 80.0 };
    OutPut(data);

    return 0;
}

void OutPut(const Score_Struct& _score)                        // byte copy => 메모리 손실 -> void OutPut(Score_Struct& _score)   
{
    cout << "name : " << _score.name << endl << endl;

    cout << "kor : " << _score.kor << endl;
    cout << "eng : " << _score.eng << endl;
    cout << "math : " << _score.math << endl << endl;

    cout << "total : " << _score.tot << endl;
    cout << "avg : " << _score.avg << endl;
}