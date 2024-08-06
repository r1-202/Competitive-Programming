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
    cin>>t;
    while(t>0)
    {
        solve_case();
        --t;
    }
}

struct graph
{
    int size;
    vector<int> depth;
    int max_depth;
    vector<vector<int>> children;
    vector<vector<int>> edge;
    vector<int> parent;
    graph(int n)
    {
        size = n;
        children = vector<vector<int>>(size,vector<int>());
        parent = vector<int>(size,-1);
        edge = vector<vector<int>>(size,vector<int>());
        max_depth =0;
        depth = vector<int>(size,0);
    }
    void dfs(int v)
    {
        for(int i=0;i<edge[v].size();++i)
        {
            int u = edge[v][i];
            if(u!=parent[v])
            {
                depth[u]=depth[v]+1;
                max_depth=max(max_depth,depth[u]);
                parent[u]=v;
                children[v].push_back(u);
                dfs(u);
            }
        }
    }
    void make_tree(int root)
    {
        parent[root]=root;
        depth[root]=0;
        max_depth=0;
        dfs(root);
    }
};
void solve_case()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    graph g(n+1);
    int x,y;
    for(int i=1;i<=n-1;++i)
    {
        cin>>x>>y;
        g.edge[x].push_back(y);
        g.edge[y].push_back(x);
    }
    g.make_tree(a);
    if(a==b)
    {
        cout<<2*(n-1)-g.max_depth<<"\n";
        return;
    }
    int d = b;
    vector<int> path;
    while(d!=a)
    {
        path.push_back(d);
        d=g.parent[d];
    }
    path.push_back(a);
    int i=path.size()/2;
    g.make_tree(path[i]);
    cout<<2*(n-1)-g.max_depth+i<<"\n";
}