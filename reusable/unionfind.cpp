#include <iostream>
#include <vector>

using namespace std;
struct graph
{
    int size;
    vector<vector<int>> edge;
    vector<int> parent;
    vector<int> root_size;
    graph(int n)
    {
        size = n;
        parent = vector<int>(size,-1);
        root_size = vector<int>(size,1);
    }
    int find(int v)
    {
        if(parent[v]==-1) return v;
        parent[v]=find(parent[v]);
        return parent[v];
    }
    void g_union(int u, int v)
    {
        int u_root = find(u);
        int v_root = find(v);
        if(u_root==v_root) return;
        if(root_size[u_root]<root_size[v_root])
        {
            parent[u_root] = v_root;
            root_size[v_root]+=root_size[u_root];
        }
        else
        {
            parent[v_root] = u_root;
            root_size[u_root]+=root_size[v_root];
        }
    }
};

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve_case();
}


void solve_case()
{
    graph g(7);
    g.g_union(1,2);
    g.g_union(1,3);
    g.g_union(1,4);
    g.g_union(5,6);
    for(int i=1;i<=6;++i) cout<<g.find(i)<<"\n";
}