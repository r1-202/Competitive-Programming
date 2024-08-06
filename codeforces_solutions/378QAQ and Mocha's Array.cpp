#include <iostream>
#include <vector>
#include <algorithm>
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
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b;
    for(int i=1;i<=n;++i) cin>>a[i];
    int min = a[1];
    for(int i=1;i<=n;++i)
    {
        if(a[i]<min) min=a[i];
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]%min!=0) b.push_back(a[i]);
    }
    if(b.size()>0) min=b[0];
    for(int i=0;i<b.size();++i)
    {
        if(b[i]<min) min=b[i];
    }
    int i;
    for(i=0;i<b.size();++i)
    {
        if(b[i]%min!=0) break;
    }
    if(b.size()>0&&i!=b.size()) cout<<"no\n";
    else cout<<"yes\n";
}