#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include<unordered_map>

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
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
  }
  if(a[0]==a[n-1])
  {
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
  cout<<"RB";
  for(int i=2;i<n;++i)
  {
    cout<<'R';
  }
  cout<<'\n';
}