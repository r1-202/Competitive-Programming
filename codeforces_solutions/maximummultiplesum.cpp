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

void solve_case()
{
  int n;
  cin>>n;
  int m=0;
  int ma=0;
  for(int i=2;i<=n;++i)
  {
    int sum=0;
    for(int j=1;j<=n/i;++j)
    {
      sum+=i*j;
    }
    if(sum>ma)
    {
      ma=sum;
      m=i;
    }
  }
  cout<<m<<'\n';
}