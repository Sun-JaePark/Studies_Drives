// 동적 할당 
// 배열을 int *arr 선언 시 -> 접근할 때 *(arr + i)  // 배열을 int arr[] 선언 시 -> 접근할 때 arr[i]

#include <iostream>

using namespace std;

int main(void)
{
    int size;

    cout << "입력 할 학생의 수 : "; 
    cin >> size;

    //int *p = new int;   //동적 메모리 할당
    //delete p;           //동적 메모리 해제

    int *arr = new int[size];   //동적 메모리 할당
    //int arr1[size];

    if (arr == NULL)
    {
        cout << "메모리 할당 실패!!!" << endl;
        return -1;
    }

    cout << endl << " ### 데이터 입력 ### " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i << " : ";
        //cin >> arr1[i];

        cin >> *(arr + i);
        
    }

    cout << endl << "### 결과 출력 ###" << endl;
    for (int i = 0; i < size; i++)
        //cout << i << " : " << arr1[i] << endl;
        cout << i << " : " << *(arr + i) << endl;

    delete []arr;       //동적 메모리 해제

    return 0;
}