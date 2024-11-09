#include <iostream>
#include <vector>
using namespace std;
#define ll long long
void solve_case();
vector<ll> factorials;
ll mod=1e9+7;
void fill_factorials()
{
    factorials=vector<ll>(2*100000+1,0);
    factorials[0]=1;
    factorials[1]=1;
    for(ll i=2;i<2*100000+1;++i)
    {
        factorials[i]=(i*factorials[i-1])%mod;
    }
}

ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
  if (b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll gcd = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

ll inverse(ll n, ll p)
{
  ll x, y;
  ll gcd = extended_gcd(n, p, x, y);
  if (gcd != 1)
  {
    return -1;
  }
  return (x % p + p) % p;
}



ll pow2(ll e)
{
    ll x=1;
    while(e>0)
    {
        x=(x<<1)%mod;
        --e;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    fill_factorials();
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
    ll X;
    cin>>n;
    cin>>X;
    ll buffer;
    ll nr_ones=0;
    for(ll i=0;i<n;++i)
    {
        cin>>buffer;
        if(buffer==1) ++nr_ones;
    }
    vector<ll> multx;
    multx.push_back(X);
    while(multx.back()<nr_ones)
    {
        multx.push_back(X*(multx.size()+1));
    }
    ll zero_perms=pow2(n-nr_ones);
    ll count = zero_perms-1;
    for(ll i=0;i<multx.size();++i)
    {
        if(multx[i]>nr_ones) continue;
        ll factor = (((factorials[nr_ones]*inverse(factorials[multx[i]],mod))%mod)
        *inverse(factorials[nr_ones-multx[i]],mod))%mod;
        count=(count+(factor*zero_perms)%mod)%mod;
    }
    cout<<count<<'\n';
}