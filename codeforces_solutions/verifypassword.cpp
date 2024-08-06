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
    char password[20];
    int strong = true;
    cin>>password[0];
    for(int i=1;i<n;++i)
    {
        cin>>password[i];
        if(password[i]<password[i-1]) strong=false;
    }
    if(strong) cout<<"yes\n";
    else cout<<"no\n";
}