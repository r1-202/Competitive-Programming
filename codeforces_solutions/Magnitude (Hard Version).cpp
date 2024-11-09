#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<ll> p2(200001);
ll m = 998244353;
void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    p2[0]=1;
    for(int i=1;i<p2.size();++i)
    {
      p2[i]=(p2[i-1]<<1)%m;
    }
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
  ll count=0;
  vector<ll> a(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
  }
  ll pre_sum=0;
  ll min_sum=a[0]+1;
  vector<int> positions;
  for(int i=0;i<n;++i)
  {
    pre_sum+=a[i];
    if(pre_sum<min_sum)
    {
      min_sum=pre_sum;
      positions.clear();
      positions.push_back(i);
    }
    else
    {
      if(pre_sum==min_sum) positions.push_back(i);
    }
  }
  if(min_sum>=0)
  {
    count = p2[n];
    cout<<count<<'\n';
    return;
  }
  pre_sum=0;
  int i=0;
  int j=0;
  int x=0;
  while(i<n)
  {
    if(i==positions[j])
    {
      int y = n-i-1;
      count=(count+p2[x+y])%m;
      ++j;
      if(j==positions.size())
      {
        break;
      }
    }
    pre_sum+=a[i];
    if(pre_sum>=0)
    {
      ++x;
    }
    ++i;    
  }
  cout<<count<<'\n';
}