#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    while(t>0)
    {
        solve_case();
        --t;
    }
}

class graph
{
public:
    vector<vector<int>> edge;
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> depth;
    vector<bool> processed;
    vector<char> win;
    queue<int> leaf;
    bool odd_depth;
    graph(int n)
    {
        edge = vector<vector<int>>(n,vector<int>());
        children = vector<vector<int>>(n,vector<int>());
        parent = vector<int>(n,-1);
        depth = vector<int>(n,0);
        processed=vector<bool>(n,false);
        win = vector<char>(n);
    }
    void make_root(int v)
    {
        parent[v]=v;
        depth[v]=0;
        dfs(v);
    }
    void dfs(int v)
    {
        for(int i=0;i<edge[v].size();++i)
        {
            int u=edge[v][i];
            if(u!=parent[v])
            {
                parent[u]=v;
                children[v].push_back(u);
                depth[u]=1+depth[v];
                dfs(u);
            }
        }
        if(edge[v].size()==1&&edge[v][0]==parent[v]) leaf.push(v);
    }
};

void solve_case()
{
    int n,t;
    cin>>n>>t;
    graph g(n+1);
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        g.edge[y].push_back(x);
        g.edge[x].push_back(y);
    }
    while(t>0)
    {
        int a;
        cin>>a;
        g.make_root(a);
        while(g.leaf.size()>0)
        {
            int u = g.leaf.front();
            g.leaf.pop();
            bool ready=true;
            for(int i=0;i<g.children[u].size();++i)
            {
                if(!g.processed[g.children[u][i]]) ready=false;
            }
            if(ready)
            {
                g.processed[u]=true;
                if(g.parent[u]!=u) g.leaf.push(g.parent[u]);
                if(g.depth[u]%2==0)
                {
                    bool ron_looses=true;
                    for(int i=0;i<g.children[u].size();++i)
                    {
                        if(g.win[g.children[u][i]]=='R') ron_looses=false;
                    }
                    if(ron_looses) g.win[u]='H';
                    else g.win[u]='R';
                }
                else
                {
                    bool her_looses=true;
                    for(int i=0;i<g.children[u].size();++i)
                    {
                        if(g.win[g.children[u][i]]=='H') her_looses=false;
                    }
                    if(her_looses) g.win[u]='R';
                    else g.win[u]='H';
                }
            }
        }
        if(g.win[a]=='R') cout<<"Ron\n";
        else cout<<"Hermione\n";
        --t;
    }
}