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
  ll n, a, b;
  cin >> n >> a >> b;
  if (b <= a)
  {
    cout << a * n << '\n';
    return;
  }
  if (n > b - a)
  {
    cout << ((a + 1 + b) * (b - a)) / 2 + (n-(b-a))*a<<'\n';
    return;
  }
  cout<<(((b-n+1+b)*(n))/2)<<'\n';
}