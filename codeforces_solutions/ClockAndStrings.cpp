#include <iostream>
using namespace std;
void solve();
int main()
{
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
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(a>b)
    {
        swap(a,b);
    }
    if(c>a&&c<b)
    {
        if(d>a&&d<b)
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    else
    {
        if(d>a&&d<b)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}