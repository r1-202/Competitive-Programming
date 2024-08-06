#include <iostream>
#include <vector>
using namespace std;

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t>0)
    {
        solve_case();
        --t;
    }
}

void solve_case()
{
    int n,x;
    cin>>n;
    cin>>x;
    vector<int> p(n+1);
    int ix;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        if(p[i]==x)ix=i;
    }
    int l=1,h=n+1;
    while(h-l!=1)
    {
        int m = l+(h-l)/2;
        if(p[m]<=x)l=m;
        else h=m;
    }
    cout<<"1\n";
    cout<<l<<' '<<ix<<'\n';
}