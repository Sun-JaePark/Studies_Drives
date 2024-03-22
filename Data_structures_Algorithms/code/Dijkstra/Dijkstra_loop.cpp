#include <iostream>

#define N INT16_MAX
#define NODE_MAX 6

using namespace std;

void GetMinNode(int* _current_node, bool* _already_path, int& _min_index)
{
    int min = N;
    for (int i = 0; i < NODE_MAX; i++)
    {
        if (!_already_path[i] && _current_node[i] < min)
        {
            min = _current_node[i];
            _min_index = i;
        }
    }
}

void Dijkstra(int* _current_node, bool* _already_path, int(* _map)[NODE_MAX], const int& _start)
{
    for (int i = 0; i < NODE_MAX; i++)
        _current_node[i] = _map[_start][i];
    
    int min_index = 0;
    int add = 0;
    for (int i = 0; i < NODE_MAX; i++)
    {
        GetMinNode(_current_node, _already_path, min_index);
        _already_path[min_index] = true;

        for (int j = 0; j < NODE_MAX; j++)
        {
            add = _current_node[min_index] + _map[min_index][j];
            !_already_path[j] && add < _current_node[j] ? _current_node[j] = add : NULL;
        
        }
        
    }
    
    
}

int main(void)
{
    int map[NODE_MAX][NODE_MAX] = 
    {
        { 0, 2, 5, 1, N, N },
        { 2, 0, 3, 2, N, N },
        { 5, 3, 0, 3, 1, 5 },
        { 1, 2, 3, 0, 1, N },
        { N, N, 1, 1, 0, 2 },
        { N, N, 5, N, 2, 0 },
    };

    bool already_path[NODE_MAX] = { 0, };
    int current_node[NODE_MAX] = { 0, };

    Dijkstra(current_node, already_path, map, 0);
    for (int i = 0; i < NODE_MAX; i++)
        cout << current_node[i] << " ";
    
    cout << endl;
    


    return EXIT_SUCCESS;
}
