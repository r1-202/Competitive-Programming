#include <iostream>
#include <vector>
#include <stack>
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

int query(int a, int b, int c, int d)
{
  cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
  cout.flush();
  char buffer;
  cin>>buffer;
  if(buffer=='<') return -1;
  if(buffer=='>') return 1;
  if(buffer=='=') return 0;
  return -2;
}

void solve_case()
{
  int n;
  cin>>n;
  int max_index = 0;
  vector<int> s;
  for(int i=0;i<n;++i)
  {
    if(query(i,i,max_index,max_index)==1)
    {
      max_index=i;
    }
  }
  s.push_back(0);
  for(int i=0;i<n;++i)
  {
    int result = query(max_index,i,max_index,s.back());
    if(result==1)
    {
      s.clear();
      s.push_back(i);
    }
    else if(result==0)
    {
      s.push_back(i);
    }
  }
  int min_index=s[0];
  for(int i=1;i<s.size();++i)
  {
    if(query(s[i],s[i],min_index,min_index)==-1)
    {
      min_index=s[i];
    }
  }
  cout<<"! "<<max_index<<" "<<min_index<<'\n';
  cout.flush();
}