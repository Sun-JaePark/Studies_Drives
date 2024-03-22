// vector와 list

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
    vector<int> v;
    list<int> l;

    for (int i = 0; i < 10; i++)
        v.emplace_back(i);
    for (int i = 0; i < 10; i++)
        l.emplace_back(i);

    // vector<int>::iterator vp;
    // list<int>::iterator lp;

    for (auto vp = v.begin(); vp != v.end(); vp++)
        cout << *vp << endl;
    for (auto lp = v.begin(); lp != v.end(); lp++)
        cout << *lp << endl;

    return 0;
}