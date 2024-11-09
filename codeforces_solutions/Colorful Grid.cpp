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
  ll m, n, k;
  cin >> n >> m >> k;
  vector<vector<char>> hor(n, vector<char>(m - 1, 'r'));
  vector<vector<char>> ver(n - 1, vector<char>(m, 'r'));
  if (k < n - 1 + m - 1 || (k - (n - 1 + m - 1) )% 2 == 1)
  {
    cout << "no\n";
    return;
  }
  cout<<"yes\n";
  for (int i = 0; i < m - 1; ++i)
  {
    if (i % 2 == 0)
      hor[0][i] = 'r';
    else
      hor[0][i] = 'b';
  }
  ver[0][0]='r';
  hor[1][0]='b';
  ver[1][0]='r';
  char last=hor[0][m-2];
  char other;
  if(last == 'r') other='b';
  else other='r';
  for(int i=0;i<n-1;++i)
  {
    if(i%2==0) ver[i][m-1] = other;
    else ver[i][m-1]=last;
  }
  last = ver[n-2][m-1];
  if(last=='r') other='b';
  else other='r';
  hor[n-1][m-2]=other;
  ver[n-2][m-2]=last;
  hor[n-2][m-2]=other;
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<m-1;++j)
    {
      cout<<hor[i][j]<<' ';
    }
    cout<<'\n';
  }
  for(int i=0;i<n-1;++i)
  {
    for(int j=0;j<m;++j)
    {
      cout<<ver[i][j]<<' ';
    }
    cout<<'\n';
  }
}