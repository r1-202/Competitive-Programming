#include <iostream>
#include <vector>
using namespace std;
#define ll long long

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

void dfs(ll x, ll y, ll z,ll k, ll x1, ll y1, ll &m)
{
  if(x1>x||y1>y)
  {
    return;
  }
  if(k%((ll)x1*(ll)y1)==0)
  {
    ll z1=k/((ll)x1*(ll)y1);
    if(z1<=z)
    {
      ll count = (ll)(x-x1+1)*(ll)(y-y1+1)*(ll)(z-z1+1);
      if(count>m)
      {
        m=count;
      }
    }
  }
  dfs(x,y,z,k,x1+1,y1,m);
  dfs(x,y,z,k,x1,y1+1,m);
}

void fill_divisors(ll a, vector<ll> &d)
{
    for(ll i=1;i*i<=a;++i)
    {
        if(a%i==0)
        {
            d.push_back(i);
            if(a/i!=i) d.push_back(a/i);
        }
    }
}

void solve_case()
{
  ll x,y,z;
  ll k;
  cin>>x>>y>>z>>k;
  vector<ll> dk;
  fill_divisors(k,dk);
  vector<vector<ll>> dkk(dk.size(),vector<ll>());
  for(ll i=0;i<dk.size();++i)
  {
    fill_divisors(dk[i],dkk[i]);
  }
  ll m=0;
  for(ll i=0;i<dk.size();++i)
  {
    for(ll j=0;j<dkk[i].size();++j)
    {
      ll x1 = dkk[i][j];
      ll y1 = dk[i]/dkk[i][j];
      ll z1 = k/dk[i];
      if(x1<=x&&y1<=y&&z1<=z)
      {
        ll count = (x-x1+1)*(y-y1+1)*(z-z1+1);
        if(count>m)
        {
          m=count;
        }
      }
    }
  }
  cout<<m<<'\n';
}