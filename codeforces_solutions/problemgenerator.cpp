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
    string s;
    cin>>s;
    int count[7]={0};
    for(int i=0;i<s.size();++i)
    {
        ++count[(int)s[i]-(int)'A'];
    }
    int extra=0;
    for(int i=0;i<7;++i)
    {
        if(m>count[i]) extra+=m-count[i];
    }
    cout<<extra<<'\n';
}