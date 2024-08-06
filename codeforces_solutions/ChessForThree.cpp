#include <iostream>
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
    int p[3];
    int c=0;
    cin>>p[0]>>p[1]>>p[2];
    while(p[1]!=0)
    {
        ++c;
        --p[1];
        --p[2];
        sort(p,p+3);
    }
    if(p[2]%2==0)
    {
        cout<<c<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
}