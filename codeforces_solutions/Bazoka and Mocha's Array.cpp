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
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    bool answer = true;
    int pmin,pmax;
    pmin = a[1];
    pmax = a[n];
    for(int i=2;i<=n;++i)
    {
        if(a[i]<a[i-1])
        {
            if(pmin>=pmax)
            {
                pmax = a[i-1];
                pmin = a[i];
            }
            else
            {
                answer = false;
                break;
            }
        }
    }
    if(answer) cout<<"yes\n";
    else cout<<"no\n";
}