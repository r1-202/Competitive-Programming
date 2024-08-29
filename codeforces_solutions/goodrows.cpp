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
    freopen("grid.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    t=1;
    while (t > 0)
    {
        solve_case();
        --t;
    }
}

void solve_case()
{
  int N,M;
  cin>>N>>M;
  vector<vector<int>> a = vector<vector<int>>(N,vector<int>(M,0));
  for(int i=0;i<N;++i)
  {
    for(int j=0;j<M;++j)
    {
      cin>>a[i][j];
    }
  }
  if(M%2==1) {cout<<"NO\n"; return;}
  for(int i=0;i<N;++i)
  {
    int count =0;
    for(int j=0;j<M;++j)
    {
      if(a[i][j]==1) ++count;
    }
    if(abs(count-M/2)>1) {cout<< "NO\n"; 
    return;}
  }
  cout<<"YES\n";
}