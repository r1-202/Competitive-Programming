#include <iostream>
using namespace std;
void solve();
string s;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        solve();
        --t;
    }
    return 0;
}
void solve()
{
    cin>>s;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]!=s[0])
        {
            swap(s[i],s[0]);
            cout<<"YES"<<endl;
            cout<<s<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}