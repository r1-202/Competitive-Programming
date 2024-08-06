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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  map<ll, vector<int>> ma;
  map<int, vector<ll>> mb;
  ll abc;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    ma[a[i]].push_back(i);
    mb[i].push_back(a[i]);
  }
  vector<ll> b(m);
  for (int i = 0; i < m; ++i)
  {
    cin >> b[i];
  }
  sort(b.data(), b.data() + m, greater<int>());
  mb[n]=vector<ll>();
  for (int i = 0; i < m; ++i)
  {
    map<ll,vector<int>>::iterator it;
    it = ma.lower_bound(b[i]);
    if(it==ma.end())
    {
      mb[n].push_back(b[i]);
    }
    else
    {
      mb[it->second.back()].push_back(b[i]);
    }
  }
  map<int,vector<ll>>::iterator in = mb.find(n);
  for(int j=0;j<in->second.size();++j)
  {
    cout<<in->second[j]<<' ';
  }
  for(int i=0;i<n;++i)
  {
    map<int,vector<ll>>::iterator it = mb.find(i);
    for(int j=0;j<it->second.size();++j)
    {
      cout<<it->second[j]<<' ';
    }
  }
  cout<<'\n';
}