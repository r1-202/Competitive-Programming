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
    solve_case();
}

void solve_case()
{
  int n;
  cin >> n;
  int buffer;
  int max = 0;
  ll sum = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> buffer;
    sum += buffer;
    if (buffer > max)
    {
      max = buffer;
    }
  }
  if (max >= 2 * (sum - max))
  {
    cout << (sum - max) << '\n';
    return;
  }
  cout << sum / 3 << '\n';
}