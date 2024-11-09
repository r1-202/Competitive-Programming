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
    int a[100];
    int b[100];

    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    int i=0,j=0,c=0;
    while(j<n)
    {
        while(b[j]>=a[i]&&j<n)
        {
            i++;
            j++;
        }
        if(j<n)
        {
            c++;
            j++;
        }
    }
    cout<<c<<"\n";
}