#include <iostream>
#include <vector>
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

struct directed_graph
{
  vector<vector<int>> edge;
  vector<int> index;
  vector<int> lowlink;
  vector<bool> on_stack;
  vector<vector<int>> scc;
  vector<int> scc_stack;

  int size;
  int current_index;
  directed_graph(int n)
  {
    size = n;
    index = vector<int>(size, -1);
    lowlink = vector<int>(size, -1);
    on_stack = vector<bool>(size, false);
    edge = vector<vector<int>>(size, vector<int>());
  }
  void tarjan()
  {
    current_index = 0;
    scc_stack.clear();
    for (int i = 0; i < size; i++)
    {
      if (index[i] == -1)
        sc(i);
    }
  }
  void sc(int v)
  {
    index[v] = current_index;
    lowlink[v] = current_index;
    ++current_index;
    scc_stack.push_back(v);
    on_stack[v] = true;

    for (int i = 0; i < edge[v].size(); i++)
    {
      int w = edge[v][i];
      if (index[w] == -1)
      {
        sc(w);
        lowlink[v] = min(lowlink[v], lowlink[w]);
      }
      else if (on_stack[w])
      {
        lowlink[v] = min(lowlink[v], index[w]);
      }
    }
    if (lowlink[v] == index[v])
    {
      scc.push_back(vector<int>());
      int w;
      do
      {
        w = scc_stack.back();
        scc_stack.pop_back();
        on_stack[w] = false;
        scc.back().push_back(w);
      } while (w != v);
    }
  }
};

void solve_case()
{
  int n, k;
  cin >> n >> k;
  directed_graph g(n + 1);
  vector<vector<int>> ss(k,vector<int>(n));
  for (int i = 0; i < k; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin>>ss[i][j];
    }
  }
  for(int i=0;i<k;++i)
  {
    for(int j=1;j<n;++j)
    {
      if(j==n-1) continue;
      g.edge[ss[i][j]].push_back(ss[i][j+1]);
    }
  }
  g.tarjan();
  for(int i=0;i<g.scc.size();++i)
  {
    if(g.scc[i].size()>1) {cout<<"no\n";return;}
  }
  cout<<"yes\n";
}