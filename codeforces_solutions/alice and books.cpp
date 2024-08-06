#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

#define ll long long
using namespace std;

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t > 0)
    {
        solve_case();
        --t;
    }
}

void solve_case()
{
  ll n;
  cin>>n;
  vector<ll> a(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
  }
  ll m=a[1];
  for(int i=1;i<n;++i)
  {
    if(a[i]>m)
    {
      m=a[i];
    }
  }
  cout<<m+a[n]<<'\n';
}