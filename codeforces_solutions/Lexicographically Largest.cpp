#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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
  set<int> used,not_used;
  vector<int> ans;
  for(int i=1;i<=n;++i)
  {
    int x;
    cin>>x;
    x+=i;
    if(used.count(x)==0)
    {
      not_used.insert(x);
    }
    int cur = *(--not_used.upper_bound(x));
    not_used.erase(cur);
    ans.push_back(cur);
    used.insert(cur);
    if(used.count(cur-1)==0)
    {
      not_used.insert(cur-1);
    }
  }
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();++i)
  {
    cout<<ans[i]<<' ';
  }
  cout<<'\n';
}