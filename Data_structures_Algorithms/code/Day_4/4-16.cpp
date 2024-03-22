// vector STL sort 알고리즘

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{   
    vector<int> v;

    v.emplace_back(5);
    v.emplace_back(8);
    v.emplace_back(1);
    v.emplace_back(3);

    sort(v.begin(), v.end());   // 오름차순
    sort(v.begin(), v.end(), greater<>());  // 내림차순 

    cout << "정렬: ";
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " ";
    cout << endl;
    
    return 0;
}
