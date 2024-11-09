#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    cin>>t;
    while(t>0)
    {
        solve_case();
        --t;
    }
}
int n;
void solve_case()
{
    int x,y;
    cin>>n>>x>>y;
    vector<int> v(x);
    for(int i=0;i<x;++i)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<int> odd_g;
    vector<int> even_g;
    int c=x-2;
    for(int i=0;i<x;++i)
    {
        int g;
        if(i==x-1)
        {
            g=n-v[i]+v[0]-1;
        }
        else
        {
            g=v[i+1]-v[i]-1;
        }
        if(g==0)
        {
            continue;
        }
        if(g==1)
        {
            ++c;
            continue;
        }
        if(g%2==0)even_g.push_back(g);
        else odd_g.push_back(g);
    }
    sort(odd_g.begin(),odd_g.end());
    sort(even_g.begin(),even_g.end());
    while(y>0&&!odd_g.empty())
    {
        if(y>=odd_g[0]/2)
        {
            y-=odd_g[0]/2;
            c+=odd_g[0];
            odd_g.erase(odd_g.begin());
        }
        else
        {
            break;
        }
    }
    while(y>0&&!even_g.empty())
    {
        if(y>=even_g[0]/2)
        {
            y-=even_g[0]/2;
            c+=even_g[0];
            even_g.erase(even_g.begin());
        }
        else
        {
            break;
        }
    }
    if((!even_g.empty()||!odd_g.empty())&&y>0)
    {
        c+=2*y;
    }
    cout<<c<<'\n';
}