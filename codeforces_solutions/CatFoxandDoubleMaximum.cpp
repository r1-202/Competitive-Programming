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
    int n;
    cin>>n;
    int q[100001];
    int index[100001];
    int fixed[100001] = {false};
    for(int i = 1;i<=n;++i)
    {
        cin>>q[i];
        q[i] = n - q[i] + 1;
        index[q[i]] = i;
    }
    int i = 2;
    while(i<n)
    {
        int m = q[i]+1;
        while(m<=n&&fixed[index[m]]) ++m;
        if(m==n+1)
        {
            i++;
        }
        else
        {
            swap(q[i],q[index[m]]);
            swap(index[q[i]],index[q[index[m]]]);
            fixed[i] = true;
            i+=2;
        }
    }
    for(int i = 1;i<=n;++i) cout<<q[i]<<" ";
    cout<<"\n";
}