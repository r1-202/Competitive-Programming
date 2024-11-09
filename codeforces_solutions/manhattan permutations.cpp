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
  ll n, k;
  cin >> n >> k;
  if (k % 2)
  {
    cout << "no\n";
    return;
  }
  if (n % 2 == 0)
  {
    if (k > (n - 1 + 1) * n / 2)
    {
      cout << "no\n";
      return;
    }
  }
  else
  {
    if(k>(n-1+2)*n/2)
    {
      cout<<"no\n";
      return;
    }
  }
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    a[i] = i;
  }
  ll sum = 0;
  int l = 1;
  int h = n;
  while (k >= sum + (a[h] - l) + (h - a[l])&&l<h)
  {
    sum += (a[h] - l) + (h - a[l]);
    swap(a[h], a[l]);
    ++l;
    --h;
  }
  if (k != sum)
  {
    if (sum < k)
    {
      ll ns;
      while (h > l)
      {
        ns = sum;
        ns += (a[h] - l) + (h - a[l]);
        if (ns == k)
        {
          swap(a[h], a[l]);
          break;
        }
        --h;
      }
    }
    if (h == l)
    {
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
  for (int i = 1; i <= n; ++i)
  {
    cout << a[i] << ' ';
  }
  cout << "\n";
}