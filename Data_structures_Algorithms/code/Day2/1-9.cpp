// namespace 별칭

#include <iostream>

using namespace std;

//namespace의 많은 사용법

namespace Park_namespace_data_temp
{
    int temp;
}

namespace Park = Park_namespace_data_temp;

int main(void)
{   
    cout << "temp : " << Park::temp << endl;
    return 0;
}