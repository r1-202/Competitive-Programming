#include <iostream>
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
    int a[50];
    for(int i=0;i<n;++i) cin>>a[i];
    int m = 3;
    for(int i=0;i<n;++i)
    {
        if(i+1==a[a[i]-1])
        {
            m=2;
            break;
        }
    }
    cout<<m<<"\n";
}