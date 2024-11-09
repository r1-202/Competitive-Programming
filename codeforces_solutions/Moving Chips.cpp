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
  vector<ll> a(n);
  ll c=0;
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    if(a[i]==1)++c;
  }
  int l;
  for(l=0;l<n;++l)
  {
    if(a[l]==1) break;
  }
  int h;
  for(h=n-1;h>=0;--h)
  {
    if(a[h]==1) break;
  }
  cout<<h-l-(c-1)<<'\n';
}