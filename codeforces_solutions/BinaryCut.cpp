#include <iostream>
using namespace std;
void solve();
string s;
int i;
int c;
bool first;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t>0)
    {
        solve();
        --t;
    }
}

void solve()
{
    cin>>s;
    c = 1;
    i=0;
    while(i<s.size()-1)
    {
        if(s[i]=='1'&&s[i+1]=='0')
        {
            ++c;
            ++i;
            if(s[0]=='0') break;
            else s[0]='0';
        }
        ++i;
    }
    while(i<s.size()-1)
    {
        if(s[i]!=s[i+1])
        {
            ++c;
        }
        ++i;
    }
    cout<<c<<endl;
}