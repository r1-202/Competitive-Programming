#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

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

int gcd(int a, int b)
{
  if (!a)
    return b;
  if (!b)
    return a;
  return gcd(b, a % b);
}

void solve_case()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> a[i][j];
    }
  }
  ll snow_sum = 0;
  ll no_snow_sum = 0;
  vector<vector<int>> at(n, vector<int>(m));
  char buffer;
  for (int i = 0; i < n; ++i)
  {
    int count = 0;
    for (int j = 0; j < m; ++j)
    {
      cin >> buffer;
      if (buffer == '0')
      {
        snow_sum += a[i][j];
        ++count;
      }
      else
      {
        no_snow_sum += a[i][j];
      }
      at[i][j]=count;
    }
  }

  if (snow_sum == no_snow_sum)
  {
    cout << "yes\n";
    return;
  }

  int d = 0;
  bool first = true;
  int k2 = k * k;

  for (int i = 0; i < n - k + 1; ++i)
  {
    for (int j = 0; j < m - k + 1; ++j)
    {
      int c = 0;
      for (int ii = i; ii < i + k; ++ii)
      {
        if(j==0)
        {
          c+=at[ii][j+k-1];
        }
        else
        {
          c+=at[ii][j+k-1]-at[ii][j-1];
        }
      }
      if (2 * c - k2 == 0)
        continue;
      if (first)
      {
        first = false;
        d = 2 * c - k2;
      }
      else
        d = gcd(d, 2 * c - k2);
    }
  }
  if (d == 0)
  {
    cout << "no\n";
    return;
  }
  if ((snow_sum - no_snow_sum) % d == 0)
  {
    cout << "yes\n";
  }
  else
  {
    cout << "no\n";
  }
}