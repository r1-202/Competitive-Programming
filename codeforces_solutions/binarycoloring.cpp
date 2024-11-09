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
    int x;
    int a[32]={0};
    cin>>x;
    int length = 0;
    while(x>0)
    {
        a[length]=x%2;
        ++length;
        x=x>>1;
    }
    for(int i=0;i<length-1;++i)
    {
        if(a[i]!=0&&a[i+1]!=0)
        {
            if(i==length-2) ++length;
            a[i+2]+=1;
            a[i+1]-=2;
            int j=i+2;
            while(a[j]>1)
            {
                a[j+1]+=1;
                a[j]-=2;
                ++j;
                if(j==length) ++length;
            }
            j=i+1;
            while(a[j]!=0&&a[j-1]!=0)
            {
                a[j]+=1;
                a[j-1]-=2;
                if(j>0) --j;
            }
        }
    }
    cout<<length<<"\n";
    for(int i=0;i<length;++i) cout<<a[i]<<" ";
    cout<<"\n";
}