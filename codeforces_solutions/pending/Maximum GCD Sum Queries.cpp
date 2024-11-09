#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
int gcd(int a,int b)
{
    if(!a) return b;
    if(!b) return a;
    return gcd(b,a%b);
}
int gcd(int a, int b, int c)
{
    return gcd(a,gcd(b,c));
}

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve_case();
}

void fill_divisors(int a, vector<int> div)
{
    for(int i=1;i*i<=a;++i)
    {
        if(a%i==0)
        {
            div.push_back(i);
            if(a/i!=i) div.push_back(a/i);
        }
    }
}
void solve_case()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1),b(n+1),c(n+1);
    vector<ll> d(n+1);
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1;i<=n;++i) cin>>b[i];
    for(int i = 1;i<=n;++i) cin>>c[i];
    for(int i = 1;i<=q;++i) cin>>d[i];

    vector<int> adiv,bdiv;
    fill_divisors(a[1],adiv);fill_divisors(b[1],bdiv);
    map<pair<int,int>,int> P;
    map<pair<int,int>,int> S;
    for(int i=0;i<adiv.size();++i)
    {
        for(int j=0;j<bdiv.size();++j)
        {
            P[pair(adiv[i],bdiv[j])]=0;
            S[pair(adiv[i],bdiv[j])]=0;
        }
    }
    for(int i=1;i<=n;++i)
    {
        ++P[pair(gcd(a[1],a[i]),gcd(b[1],b[i]))];
        ++P[pair(gcd(a[1],b[i]),gcd(b[1],a[i]))];
        S[pair(gcd(a[1],b[i]),gcd(b[1],a[i]))]+=c[i];
        --P[pair(gcd(a[1],a[i],b[i]),gcd(b[1],a[i],b[i]))];
        S[pair(gcd(a[1],a[i],b[i]),gcd(b[1],a[i],b[i]))]-=c[i];
    }
    
}