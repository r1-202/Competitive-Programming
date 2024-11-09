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
typedef long long ll;
ll r;
ll r1;
int x,y;
ll up,lef;
int n;
void solve_case()
{
    cin>>r;
    x=r;
    r1 = (r+1)*(r+1);
    r=r*r;
    y = 1;
    n = 0;
    int i = 1;
    while(y<x)
    {
        ++n;
        up = ll(x)*ll(x)+ll(y+1)*ll(y+1);
        if(up<r1)
        {
            ++y;
        }
        else
        {
            lef = ll(x-1)*ll(x-1)+ll(y)*ll(y);
            if(lef>=r)
            {
                --x;
            }
            else
            {
                ++y;
                --x;
            }
        }
        ++i;
    }
    n*=8;
    n+=4;
    if(x==y)
    {
        n+=4;
    }


    
    cout<<n<<"\n";
}