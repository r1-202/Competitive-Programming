#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include<unordered_map>
#include <set>

#define ll long long
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
  cin>>n;
  int k;
  cin>>k;
  int nm;
  if(n%2==0) nm=0;
  else nm=1;
  map<int,vector<int>> a;
  int buffer;
  for(int i=0;i<n;++i)
  {
    cin>>buffer;
    a[buffer%k].push_back(buffer/k);
  }
  for(auto i=a.begin();i!=a.end();++i)
  {
    sort(i->second.begin(),i->second.end());
  }
  int ans=0;
  for(auto i=a.begin();i!=a.end();++i)
  {
    if(i->second.size()%2==0)
    {
      for(int j=0;j<i->second.size();j+=2)
      {
        ans+=(i->second[j+1]-i->second[j]);
      }
    }
    else
    {
      if(nm==0)
      {
        cout<<"-1\n";
        return;
      }
      --nm;
      vector<int> pre(i->second.size());
      vector<int> post(i->second.size());
      pre[0]=0;
      for(int j=2;j<pre.size();j+=2)
      {
        pre[j]=pre[j-2]+i->second[j-1]-i->second[j-2];
      }
      post[post.size()-1]=0;
      for(int j=post.size()-3;j>=0;j-=2)
      {
        post[j]=post[j+2]+i->second[j+2]-i->second[j+1];
      }
      int m=pre[0]+post[0];
      for(int j=0;j<pre.size();j+=2)
      {
        m=min(m,pre[j]+post[j]);
      }
      ans+=m;
    }
  }
  cout<<ans<<'\n';
}