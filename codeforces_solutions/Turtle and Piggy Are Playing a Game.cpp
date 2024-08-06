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
  int r;
  cin>>r>>r;
  int lr=0;
  int rlr=1;
  while(rlr<=r)
  {
    ++lr;
    rlr=rlr<<1;
  }
  --lr;
  cout<<lr<<'\n';
}