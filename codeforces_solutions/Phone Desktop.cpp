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
    int x,y;
    cin>>x>>y;

    int screens;
    if(y%2==0) 
    {
        screens=y/2;
        if(x>7*screens)
        {
            x-=7*screens;
            if(x%15==0)
            {
                screens+=x/15;
            }
            else
            {
                screens+=x/15 +1;
            }
        }
    }
    else
    {
        screens = y/2 + 1;
        if(x>(screens-1)*7+11)
        {
            x-=(screens-1)*7+11;
            if(x%15==0)
            {
                screens+=x/15;
            }
            else
            {
                screens+=x/15 + 1;
            }
        }
    }
    cout<<screens<<"\n";
}