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
  int t;
  cin >> t;
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
  vector<ll> a(n);
  int count = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }
  if (a[0] == 0)
    ++count;
  ll m = a[0];
  int mi = 0;
  ll sum=0;
  for (int i = 1; i < n; ++i)
  {
    if(a[i]>m)
    {
      sum+=m;
      m=a[i];
      mi=i;
    }
    else
    {
      sum+=a[i];
    }
    if(sum==m) ++count;
  }
  cout << count << '\n';
}