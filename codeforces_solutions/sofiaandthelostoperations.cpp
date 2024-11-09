#include <iostream>
#include <vector>
#include <map>
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
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    vector<int> b(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
    }
    int m;
    cin>>m;
    map<int,int> d;
    int buffer;
    for(int i=1;i<=m;++i)
    {
        cin>>buffer;
        if(d.find(buffer)==d.end())
        {
            d[buffer]=1;
        }
        else
        {
            ++d[buffer];
        }
    }
    bool last_needed=false;
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=b[i])
        {
            auto p = d.find(b[i]);
            if(p==d.end())
            {
                cout<<"no\n";
                return;
            }
            if(p->second==0)
            {
                cout<<"no\n";
                return;
            }
            --d[p->first];
        }
        if(b[i]==buffer) last_needed=true;
    }
    if(last_needed) cout<<"yes\n";
    else cout<<"no\n";
}