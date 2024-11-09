#include <iostream>
using namespace std;
void solve();
int x,y;
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
    cin>>x>>y;
    cout<<min(x,y)<<" "<<max(x,y)<<endl;
}