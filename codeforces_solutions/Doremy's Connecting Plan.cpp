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
  int n;
  ll c;
  cin>>n>>c;
  vector<ll> a(n+1);
  vector<int> ai(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    ai[i]=i;
  }

  sort(ai.data()+2,ai.data()+n+1,[&](int i1, int i2){return i1*c-a[i1]<i2*c-a[i2];});
  ll sum=a[1];
  int i;
  for(i=2;i<=n;++i)
  {
    if(sum<ai[i]*c-a[ai[i]])
    {
      break;
    }
    else
    {
      sum+=a[ai[i]];
    }
  }
  if(i==n+1)
  {
    cout<<"yes\n";
  }
  else
  {
    cout<<"no\n";
  }
}