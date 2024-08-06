#include <iostream>
#include <vector>
using namespace std;

void partition(int k, vector<vector<int>> &partitions, vector<int> &v)
{
    if(k==0) partitions.push_back(v);
    for(int i=1;i<=k;++i)
    {
        v.push_back(i);
        partition(k-i,partitions,v);
        v.pop_back();
    }
}

int main()
{
    vector<vector<int>> partitions;
    vector<int> v;
    partition(0,partitions, v);
    cout<<"\n";
    if(partitions[0].empty())cout<<"emptyyyyyyyyyyyy";
    for(int i=0;i<partitions.size();++i)
    {
        for(int j=0;j<partitions[i].size();++j)
        {
            cout<<partitions[i][j]<<" ";
        }
        cout<<"\n";
    }
}