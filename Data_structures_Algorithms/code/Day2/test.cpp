#include <iostream>

using namespace std;

void SCORE(const double *, int n, double &, double &, double &);

int main(void)
{
    int size = 0;

    cout << "입력할 학생(성적) 수 : ";
    cin >> size;

    double *score = new double[size];
    double sum = .0, avg = .0, max = .0;

    for (int i = 0; i < size; i++)
        cin >> *(score + i);        //  배열 접근 방법
    
    SCORE(score, size, sum, avg, max);

    cout << endl << " ### 성적 결과 출력 ###" << endl << endl;
    cout << "학생 수 : " << size << endl;
    cout << "총  점 : " << sum << endl;
    cout << "평  균 : " << avg << endl;
    cout << "최대값 : " << max << endl << endl;

    delete []score;
    return 0;
}

void SCORE(const double * _arr, int _size, double & _sum, double & _avg, double & _max)
{
    for (int i = 0; i < _size; i++)
    {
        _sum += *(_arr + i);

        if (_max < *(_arr + i))
            _max = *(_arr + i);
    }
    _avg = _sum / _size;
}