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

bool check_greater(int i, int j, vector<vector<ll>> &a, int n, int m)
{
  ll ma = 0;
  pair<int, int> d(i + 1, j);
  pair<int, int> u(i - 1, j);
  pair<int, int> l(i, j - 1);
  pair<int, int> r(i, j + 1);
  if (d.first >= 0 && d.first < n && d.second >= 0 && d.second < m)
  {
    ma = max(ma, a[d.first][d.second]);
    if (a[d.first][d.second] >= a[i][j])
      return false;
  }
  if (u.first >= 0 && u.first < n && u.second >= 0 && u.second < m)
  {
    ma = max(ma, a[u.first][u.second]);
    if (a[u.first][u.second] >= a[i][j])
      return false;
  }
  if (l.first >= 0 && l.first < n && l.second >= 0 && l.second < m)
  {
    ma = max(ma, a[l.first][l.second]);
    if (a[l.first][l.second] >= a[i][j])
      return false;
  }
  if (r.first >= 0 && r.first < n && r.second >= 0 && r.second < m)
  {
    ma = max(ma, a[r.first][r.second]);
    if (a[r.first][r.second] >= a[i][j])
      return false;
  }
  a[i][j] = ma;
  return true;
}

void solve_case()
{
  int n;
  int m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m));
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> a[i][j];
    }
  }
  int i;
  for (i = 0; i < n; ++i)
  {
    int j;
    for (j = 0; j < m; ++j)
    {
      check_greater(i, j, a, n, m);
    }
    if (j < m)
      break;
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}