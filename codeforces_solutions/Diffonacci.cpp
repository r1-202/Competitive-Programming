#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

#define ll long long
using namespace std;

vector<int> fib;

void create_fib(vector<int> &fib)
{
  fib.push_back(0);
  fib.push_back(1);
  for (int i = 0; i < 1000000000; ++i)
  {
    if (fib.back() > 1000000000)
      break;
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
}

void solve_case();
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  create_fib(fib);
  while (t > 0)
  {
    solve_case();
    --t;
  }
}

void solve_case()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  unordered_map<int, int> m;
  m[a[0]] = 1;
  int ans = 1;
  for (int i = 1; i < n; ++i)
  {
    if (m.find(a[i]) != m.end())
    {
      ++m[a[i]];
    }
    else
    {
      m[a[i]] = 1;
    }
    for (int j = 2; j < fib.size(); ++j)
    {
      if (m.find(a[i] - fib[j]) != m.end())
      {
        m[a[i]] = max(m[a[i]], m[abs(a[i] - fib[j])] + 1);
      }
      if (m.find(a[i] + fib[j]) != m.end())
      {
        m[a[i]] = max(m[a[i]], m[a[i] + fib[j]] + 1);
      }
    }
    ans = max(m[a[i]], ans);
  }
  cout << ans<< '\n';
}