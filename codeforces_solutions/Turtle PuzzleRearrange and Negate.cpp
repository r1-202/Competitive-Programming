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
  ll n;
  cin>>n;
  ll sum=0;
  ll buffer;
  for(int i=0;i<n;++i)
  {
    cin>>buffer;
    sum+=abs(buffer);
  }
  cout<<sum<<'\n';
}