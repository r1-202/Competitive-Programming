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
    //freopen("lucky.in", "r", stdin);
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
  int n;
  cin>>n;
  vector<pair<int,int>> a(n);
  map<int,bool> e;
  for(int i=0;i<n;++i)
  {
    cin>>a[i].first;
    cin>>a[i].second;
    e[i]=true;
  }
  sort(a.begin(),a.end());
  priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> m;
  for(int i=0;i<n-1;++i)
  {
    if(a[i].second<=a[i+1].second) continue;
    double t = (double)(a[i+1].first-a[i].first)/(double)(a[i].second-a[i+1].second);
    m.push(pair(t,i));
  }
  double ans = 0;
  while(!m.empty())
  {
    pair<double,int> p = m.top();
    m.pop();
    auto e1 = e.find(p.second);
    if(e1==e.end()) continue;
    ans = p.first;
    e.erase(e1);
    e1 = e.lower_bound(p.second+1);
    if(e1==e.end()) continue;
    int ne = e1->first;
    if(e1==e.begin()) continue;
    int pr = std::prev(e1)->first;
    if(a[pr].second<=a[ne].second) continue;
    double d = (double)a[ne].first+(double)a[ne].second*ans -((double)a[pr].first+(double)a[pr].second*ans);
    m.push(pair(ans+d/((double)a[pr].second-(double)a[ne].second),pr));
  }
  cout<<ans<<'\n';
}