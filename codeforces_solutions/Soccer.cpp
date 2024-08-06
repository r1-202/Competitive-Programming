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
  int x1,y1;
  cin>>x1>>y1;
  int x2,y2;
  cin>>x2>>y2;
  if((x1>y1&&x2>y2)||(x1<y1&&x2<y2))
  {
    cout<<"yes\n";
    return;
  }
  cout<<"no\n";
}