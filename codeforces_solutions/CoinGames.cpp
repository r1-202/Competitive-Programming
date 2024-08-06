#include <iostream>
using namespace std;

void solve_case();
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    string s;
    cin>>s;
    int count = 0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='U') ++count;
    }
    if(count%2==1) cout<<"yes\n";
    else cout<<"no\n";
}