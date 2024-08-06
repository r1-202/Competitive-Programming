#include <iostream>
#include <vector>
using namespace std;
int main()
{

}

struct graph
{
    int size;
    vector<vector<int>> edge;
    vector<int> cc_index;
    graph(int n)
    {
        size = n;
        edge = vector<vector<int>>(size,vector<int>());
        cc_index = vector<int>(size);
    }
};
