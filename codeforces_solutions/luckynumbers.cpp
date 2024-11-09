#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

#define ll long long
using namespace std;

bool check_lucky(vector<int> i, int X)
{
  if (i.size() == 0)
    return true;
  for (int j = 0; j < i.size() - 1; ++j)
  {
    if (i[j + 1] - i[j] > X)
      return false;
  }
  return true;
}

vector<vector<int>> clc=vector(9,vector<int>());

void calculate(vector<vector<int>> &clc)
{
  for (int i = 0; i <= 8; ++i)
  {
    clc[i].push_back(1);
  }
  for (int k = 1; k <= 1000000; ++k)
  {
    int i=k;
    vector<int> digits;
    int d;
    while (i > 0)
    {
      d = i % 10;
      digits.push_back(d);
      i = i / 10;
    }
    sort(digits.begin(), digits.end());
    for (int j = 0; j <= 8; ++j)
    {
      if (check_lucky(digits, j))
        clc[j].push_back(clc[j].back() + 1);
      else
        clc[j].push_back(clc[j].back());
    }
  }
}

void solve_case();
int main()
{
  freopen("lucky.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  calculate(clc);
  while (t > 0)
  {
    solve_case();
    --t;
  }
}

void solve_case()
{
  int L,R,X;
  cin>>L>>R>>X;
  if(X>=9)
  {
    cout<<R-L+1<<'\n';
    return;
  }
  else
  {
    if(clc[X][L]==clc[X][L-1])
    {
      cout<<clc[X][R]-clc[X][L]<<'\n';
      return;
    }
    else
    {
      cout<<clc[X][R]-clc[X][L]+1<<'\n';
      return;
    }
  }
}