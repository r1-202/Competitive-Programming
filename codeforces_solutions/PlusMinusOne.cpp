#include <iostream>
#include <vector>

using namespace std;

void solve_case();
int t;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t>0)
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
    vector<int> scc_index;
    int size;
    int current_index;
    directed_graph(int n)
    {
        size = n;
        index=vector<int>(size,-1);
        lowlink=vector<int>(size,-1);
        on_stack=vector<bool>(size,false);
        scc_index=vector<int>(size,-1);
        edge=vector<vector<int>>(size,vector<int>());
    }
    void tarjan()
    {
        current_index=0;
        scc_stack.clear();
        for(int i = 0;i<size;i++)
        {
            if(index[i]==-1)
                sc(i);
        }
    }
    void sc(int v)
    {
        index[v]=current_index;
        lowlink[v]=current_index;
        ++current_index;
        scc_stack.push_back(v);
        on_stack[v]=true;

        for(int i=0;i<edge[v].size();i++)
        {
            int w = edge[v][i];
            if(index[w]==-1)
            {
                 sc(w);
                lowlink[v]=min(lowlink[v],lowlink[w]);
            }
            else if (on_stack[w])
            {
                lowlink[v]=min(lowlink[v],index[w]);
            }

        }
        if(lowlink[v]==index[v])
        {
            scc.push_back(vector<int>());
            int w;
            do
            {
                w=scc_stack.back();
                scc_stack.pop_back();
                on_stack[w]=false;
                scc.back().push_back(w);
                scc_index[w]=scc.size()-1;
            }
            while(w!=v);
        }
    }
};

int get_position(int x)
{
    if(x>0)
    {
        return x+n-1;
    }
    else if (x<0)
    {
        return x+n;
    }
    else
    {
        cout<<"errorororoeoeoreoraoreoroa";
        return -1;
    }
}
void solve_case()
{
    int g[3][500];
    cin>>n;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>g[i][j];
        }
    }

    directed_graph G(2*n);
        int m = G.edge.size();
    for(int i=0;i<n;i++)
    {
        G.edge[get_position(-g[0][i])].push_back(get_position(g[1][i]));
        G.edge[get_position(-g[0][i])].push_back(get_position(g[2][i]));

        G.edge[get_position(-g[1][i])].push_back(get_position(g[0][i]));
        G.edge[get_position(-g[1][i])].push_back(get_position(g[2][i]));

        G.edge[get_position(-g[2][i])].push_back(get_position(g[1][i]));
        G.edge[get_position(-g[2][i])].push_back(get_position(g[0][i]));
    }
    int i;
    G.tarjan();
    for(i=1;i<=n;i++)
    {
        if(G.scc_index[get_position(i)]==G.scc_index[get_position(-i)])
        {
            cout<<"no\n";
            break;
        }
    }
    if(i == n+1)
    {
        cout<<"yes\n";
    }
}