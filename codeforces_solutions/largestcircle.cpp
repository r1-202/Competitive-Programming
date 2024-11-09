#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include<unordered_map>

#define ll long long
using namespace std;

void solve_case();
int main()
{
    //freopen("lucky.in", "r", stdin);
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
  int K;
  cin>>n>>K;
  vector<int> d(n+1);
  for(int i=1;i<=n;++i) cin>>d[i];
  vector<double> r(n+1);
  long long s = 0;
  int mone = -1;
  for(int i=1;i<n;++i)
  {
    s+=(mone)*(K-d[i]);
    mone*=-1;
  }
  s+=(K-d[n]);
  r[n]=(double)s/(double)2;
  for(int i=n-1;i>=1;--i)
  {
    r[i]=(double)K-(double)d[i]-r[i+1];
  }
  double m=r[1];
  int k=1;
  for(int i=2;i<=n;++i)
  {
    if(r[i]>m)
    {
      m=r[i];
      k=i;
    }
  }
  cout<<k<<'\n';
}