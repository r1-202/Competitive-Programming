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

int middle(int a,int b, int c)
{
    if(a>b)
    {
        if(c<b) return b;
        if(c>a) return a;
        else return c;
    }
    else
    {
        if(c>b) return b;
        if(c<a) return a;
        else return c;
    }
}

void solve_case()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int maxmin;
    if(n>2) maxmin = middle(a[3],a[1],a[2]);
    else maxmin= min(a[1],a[2]);
    for(int i=2;i<n-1;++i)
    {
        int pminmax = middle(a[i+2],a[i],a[i+1]);
        if(pminmax>maxmin) maxmin=pminmax;
    }
    cout<<maxmin<<"\n";
}