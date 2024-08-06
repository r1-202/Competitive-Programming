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
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int fav_n=a[f-1];
    sort(a.begin(),a.end(),greater<int>());
    if(k==n)
    {
        cout<<"yes\n";
        return;
    }
    if(a[k-1]>fav_n)
    {
        cout<<"no\n";
        return;
    }
    if(a[k-1]<fav_n)
    {
        cout<<"yes\n";
        return;
    }
    if(a[k-1]==fav_n)
    {
        if(a[k]==fav_n) cout<<"maybe\n";
        else cout<<"yes\n";
    }
}