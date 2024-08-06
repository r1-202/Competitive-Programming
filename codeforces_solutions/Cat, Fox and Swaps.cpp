#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
struct graph
{
    ll size;
    vector<vector<ll>> edge;
    vector<ll> parent;
    vector<ll> child;
    vector<ll> root_size;
    graph(ll n)
    {
        size = n;
        parent = vector<ll>(size,-1);
        child = vector<ll>(size,-1);
        root_size = vector<ll>(size,1);
    }
    ll find(ll v)
    {
        if(parent[v]==-1) return v;
        parent[v]=find(parent[v]);
        return parent[v];
    }
    void g_union(ll u, ll v)
    {
        ll u_root = find(u);
        ll v_root = find(v);
        if(u_root==v_root) return;
        if(root_size[u_root]<=root_size[v_root])
        {
            parent[u_root] = v_root;
            child[v_root] = u_root;
            root_size[v_root]+=root_size[u_root];
        }
        else
        {
            parent[v_root] = u_root;
            child[u_root] = v_root;
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
    ll t;
    cin>>t;
    while(t>0)
    {
        solve_case();
        --t;
    }
}


void solve_case()
{
    ll n;
    cin>>n;
    vector<ll> p(n+1);
    for(ll i = 1;i<=n;++i) cin>>p[i];
    ll max_displaced = n+1;
    ll min_displaced = 0;
    for(ll i = 1;i<=n;++i)
    {
        if(p[i]!=i)
        {
            min_displaced = i;
            break;
        }
    }
    for(ll i=n;i>=1;--i)
    {
        if(p[i]!=i)
        {
            max_displaced=i;
            break;
        }
    }
    if(min_displaced==0)
    {
        cout<<2*n*(2*n+1)/2<<"\n";
        return;
    }
    ll l,r;
    ll count=0;
    for(l=1;l<=min_displaced+n;++l)
    {
        count+=2*n-max(l+1,max_displaced+1)+1;
    }
    graph g(n+1);
    for(ll i =1;i<=n;++i)
    {
        g.g_union(i,p[i]);
    }
    ll i;
    ll sum;
    bool search = false;
    for(i=1;i<=n;++i)
    {
        if(g.parent[i]==-1&&g.root_size[i]>1)
        {
            if(g.root_size[i]==2)
            {
                search = true;
                sum = i+g.child[i];
            }
            break;
        }
    }
    if(search)
    {
        for(i=i+1;i<=n;++i)
        {
            if(g.parent[i]==-1&&(g.root_size[i]>2||(g.root_size[i]==2&&i+g.child[i]!=sum)))
            {
                break;
            }
        }
        if(i==n+1) ++count;
    }
    cout<<count<<"\n";
}