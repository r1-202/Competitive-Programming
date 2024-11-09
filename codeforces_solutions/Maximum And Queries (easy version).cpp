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
  ll t = 1;
  // cin >> t;
  while (t > 0)
  {
    solve_case();
    --t;
  }
}

ll getMask(ll n)
{
  ll mask = 0;
  if (n == 0)
    return mask;
  mask = 1 << 1;
  n = n >> 1;
  while (n != 0)
  {
    mask = (mask << 1) + 1;
    n = n >> 1;
  }
  return mask;
}

void solve_case()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> k(q);
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i)
  {
    cin >> k[i];
  }
  for (int i = 0; i < q; ++i)
  {
    ll ki = k[i];
    vector<ll> r = a;
    ll maximum = 0;
    for (int j = 60; j >= 0; --j)
    {
      ll bit = (ll)1 << j;
      ll cki = ki;
      int k;
      vector<ll> rollback = r;
      for (k = 0; k < n; ++k)
      {
        if(!(r[k]&bit))
        {
          if(bit-(r[k]%bit)<=cki)
          {
            cki-=bit-r[k]%bit;
            r[k]+=bit-r[k]%bit;
          }
          else
          {
            break;
          }
        }
      }
      if(k==n)
      {
        maximum+=bit;
        ki=cki;
      }
      else
      {
        r=rollback;
      }
    }
    cout<<maximum<<'\n';
  }
}