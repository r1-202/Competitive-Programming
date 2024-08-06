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
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    cin >> a[i];
  }
  ll max_sum_even;
  ll max_sum_odd;
  int max_one = 0;
  int min_one = n + 1;
  ll sum = 0;
  for (int i = 1; i <= n; ++i)
  {
    if (a[i] == 1)
    {
      max_one = max(max_one, i);
      min_one = min(min_one, i);
    }
    sum += a[i];
  }
  if (sum % 2 == 0)
  {
    max_sum_even = sum;
    max_sum_odd = sum - min((int)n - max_one, min_one - 1) * 2 - 1;
  }
  else
  {
    max_sum_odd = sum;
    max_sum_even = sum - min((int)n - max_one, min_one - 1) * 2 - 1;
  }
  for (int k = 0; k < q; ++k)
  {
    int state;
    cin >> state;

    if (state == 1)
    {
      ll s;
      cin >> s;
      if (s % 2 == 0)
      {
        if (s <= max_sum_even)
        {
          cout << "yes\n";
        }
        else
        {
          cout << "no\n";
        }
      }
      else
      {
        if (s <= max_sum_odd)
        {
          cout << "yes\n";
        }
        else
        {
          cout << "no\n";
        }
      }
    }
    else
    {
      int i;
      ll v;
      cin >> i >> v;
      if (a[i] == v)
        continue;
      a[i] = v;
      if (v == 1)
      {
        min_one = min(i, min_one);
        max_one = max(i, max_one);
        --sum;
      }
      else
      {
        ++sum;
        if(i==max_one)
        {
          int j;
          for(j=max_one;j>0;--j)
          {
            if(a[j]==1) break;
          }
          max_one=j;
        }
        if(i==min_one)
        {
          int j;
          for(j=min_one;j<n+1;++j)
          {
            if(a[j]==1) break;
          }
          min_one=j;
        }
      }
      if (sum % 2 == 0)
      {
        max_sum_even = sum;
        max_sum_odd = sum - min((int)n - max_one, min_one - 1) * 2 - 1;
      }
      else
      {
        max_sum_odd = sum;
        max_sum_even = sum - min((int)n - max_one, min_one - 1) * 2 - 1;
      }
    }
  }
}