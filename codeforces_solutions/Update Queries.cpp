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
  int n,m;
  cin>>n>>m;
  vector<char> s(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>s[i];
  }
  vector<int> ind(m);
  for(int i=0;i<m;++i)
  {
    cin>>ind[i];
  }
  vector<char> c(m);
  for(int i=0;i<m;++i)
  {
    cin>>c[i];
  }
  sort(ind.begin(),ind.end());
  sort(c.begin(),c.end());
  int i=0;int j=0;
  s[ind[i]]=c[j];
  ++i;
  ++j;
  while(i<m)
  {
    if(ind[i]!=ind[i-1])
    {
      s[ind[i]]=c[j];
      ++j;
    }
    ++i;
  }
  for(int k=1;k<=n;++k)
  {
    cout<<s[k];
  }
  cout<<'\n';
}