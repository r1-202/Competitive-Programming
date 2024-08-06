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
    int a,b,c;
    cin>>a>>b>>c;
    if(a!=c-1)
    {
        cout<<"-1\n";
        return;
    }
    if(a==0)
    {
        cout<<b<<"\n";
        return;
    }
    int depth;
    for(depth=0;(1<<(depth+1))-1<a;++depth);
    int down_positions;
    int positions_left=(1<<(depth+1))-1-a;
    down_positions=(1<<depth)-positions_left;
    down_positions = down_positions<<1;
    if(b<=positions_left)
    {
        cout<<depth+1<<"\n";
        return;
    }
    b-=positions_left;
    down_positions+=positions_left;
    depth+=b/down_positions;
    b=b%down_positions;
    if(b==0)
    {
        cout<<depth+1<<"\n";
        return;
    }
    cout<<depth+2<<"\n";
}