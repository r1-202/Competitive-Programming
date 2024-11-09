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
    int n,m;
    cin>>n>>m;
    if(m>n)
    {
        cout<<"no\n";
        return;
    }

    if((n-m)%2==0)
    {
        cout<<"yes\n";
    }
    else
    {
        cout<<"no\n";
    }
}