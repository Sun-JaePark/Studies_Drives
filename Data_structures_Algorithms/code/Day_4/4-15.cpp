//STL sort 알고리즘

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int arr[] = { 45, 23, 36, 87, 56 };
    int arrSize = sizeof(arr) / sizeof(*arr);

    sort(arr, arr + arrSize);

    cout << "정렬: ";
    for (int* p = arr; p < arr + arrSize; p++)
        cout << *p << " ";
    cout << endl;
    
    return 0;
}