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
  vector<ll> a(3);
  cin>>a[0];cin>>a[1];cin>>a[2];
  sort(a.begin(),a.end());
  cout<<a[2]-a[0]<<'\n';
}