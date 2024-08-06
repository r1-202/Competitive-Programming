#include <iostream>
#include <map>
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
    int n;
    cin>>n;
    bool used[26] = {false};
    int index[26];
    char encoding[26];
    int length=0;
    char d[200000];
    for(int i=0;i<n;++i) 
    {
        cin>>d[i];
        used[(int)(d[i])-97] = true;
    }
    for(int i=0;i<26;++i)
    {
        if(used[i])
        {
            encoding[length]=(char)(i+97);
            index[i]=length;
            ++length;
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<encoding[length - index[(int)d[i]-97] - 1];
    }
    cout<<"\n";
}