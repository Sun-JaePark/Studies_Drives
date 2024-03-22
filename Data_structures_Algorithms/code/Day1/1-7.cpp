#include <iostream>
#include <vector>
#include <random>

using namespace std;

void Func(u_int& _max_value)
{
    vector<u_int> num_vector;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<u_int> dis(0, 9999);

    for (int i = 0; i < 1000; i++)
        num_vector.emplace_back(dis(gen));
    
    for (int i = 0; i < num_vector.size(); i++)
    {
        if (_max_value < num_vector[i])
            _max_value = num_vector[i];
    }
}

int main(void)
{
    u_int max_value = 0;
    Func(max_value);
    cout << max_value << endl;

    return 0;
}