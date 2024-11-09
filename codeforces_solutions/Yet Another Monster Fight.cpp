#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
 
#define ll long long
using namespace std;
 
void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin >> t;
    while (t > 0)
    {
        solve_case();
        --t;
    }
}
 
void solve_case()
{
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
  }
  vector<int> lpi(n);
  vector<ll> lp(n);
  vector<int> rpi(n);
  vector<ll> rp(n);
  for(int i=0;i<n;++i)
  {
    lpi[i]=i;
    lp[i]=a[i]+i;
    rpi[i]=i;
    rp[i]=a[i]+(n-1)-i;
  }
  int l=0;
  int h=n-1;
  sort(rpi.begin(),rpi.end(),[&](int i1, int i2)->bool{return rp[i1]<rp[i2];});
  sort(lpi.begin(),lpi.end(),[&](int i1, int i2)->bool{return lp[i1]<lp[i2];});
  int lpii=n-1;
  int rpii=n-1;
  while(l!=h)
  {
    while(rpi[rpii]<l||rpi[rpii]>h)
    {
      --rpii;
    }
    while(lpi[lpii]<l||lpi[lpii]>h)
    {
      --lpii;
    }
    if(rp[rpi[rpii]]>lp[lpi[lpii]])
    {
      h=rpi[rpii];
      --rpii;
    }
    else
    {
      l=lpi[lpii];
      --lpii;
    }
  }
  ll mp=0;
  for(int i=0;i<n;++i)
  {
    if(i<l)
    {
      mp=max(a[i]+n-1-i,mp);
    }
    else if(i>l)
    {
      mp=max(a[i]+i,mp);
    }
    else if(i==l)
    {
      mp=max(a[i],mp);
    }
  }
  cout<<mp<<'\n';
}