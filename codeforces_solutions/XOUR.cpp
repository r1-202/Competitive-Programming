#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

void solve_case();
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t>0)
    {
        solve_case();
        --t;
    }
}


void solve_case()
{
    int n;
    int s;
    int i,j;
    int a[200000];
    int buffer;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> m;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>buffer;
        a[i]=buffer;
        s=buffer>>2;
        m[s].push(buffer);
    }
    for(i=0;i<n;++i)
    {
        s=a[i]>>2;
        cout<<m[s].top()<<" ";
        m[s].pop();
    }
    cout<<"\n";
}