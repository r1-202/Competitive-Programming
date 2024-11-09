#include <iostream>
#include <vector>
#define ll long long
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

ll find_min(vector<ll> &v,int first,int last )
{
    ll m=v[first];
    for(int i=first;i<=last;++i)
    {
        m=min(v[i],m);
    }
    return m;
}
const ll INF = 1e18;
void solve_case()
{
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,INF));
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=k;++j)
        {
            ll mn = INF;
            for(int d=0;j+d<=k&&i+d<n;++d)
            {
                mn=min(mn,a[i+d]);
                dp[i+d+1][j+d]=min(dp[i+d+1][j+d],dp[i][j]+(d+1)*mn);
            }
        }
    } 
    cout<<find_min(dp[n],0,dp[n].size()-1)<<'\n';
}