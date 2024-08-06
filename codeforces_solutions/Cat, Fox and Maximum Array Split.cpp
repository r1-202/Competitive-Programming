#include <iostream>
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
int query(int j, int k)
{
    int buffer;
    cout<<"? "<<j<<" "<<k<<"\n";
    cout.flush();
    cin>>buffer;
    return buffer;
}

void solve_case()
{
    int n,k;
    int max;
    int i;
    cin>>n>>k;
    for(i=n;i<n*n;i+=n)
    {
        if(query(1,i)==n) break;
    }
    max = i/n;
    i = max*(n/k);
    while(i>0)
    {
        int current = 1;
        int j;
        for(j = 1;j<k;++j)
        {
            current = query(current,i);
            ++current;
            if(current > n) break;
        }
        if(j==k&&query(current,i)==n)
        {
            cout<<"! "<<i<<"\n";
            cout.flush();
            cin>>i;
            return;
        }
        i-=max;
    }
    cout<<"! -1\n";
    cout.flush();
    cin>>i;
}