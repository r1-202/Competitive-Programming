#include <vector>
#include <iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    if(!a) return b;
    if(!b) return a;
    return gcd(b,a%b);
}


void fill_divisors(ll a, vector<ll> &d)
{
    for(ll i=1;i*i<=a;++i)
    {
        if(a%i==0)
        {
            d.push_back(i);
            if(a/i!=i) d.push_back(a/i);
        }
    }
}

ll get_lcm(ll a, ll b)
{
    ll d = gcd(a,b);
    return (ll)(a)*(ll)(b)/(ll)(d);
}

int main()
{
  vector<ll> d;
  ll n;
  cin>>n;
  fill_divisors(n,d);
  for(ll i=0;i<d.size();++i)
  {
    cout<<d[i]<<'\n';
  }
}