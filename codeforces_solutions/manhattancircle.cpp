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
  int n,m;
  cin>>n>>m;
  vector<int> in(n+1,0);
  vector<int> jn(m+1,0);
  int im=0,jm=0;
  int imn=0,jmn=-1;
  char buffer;
  for(int i=1;i<=n;++i)
  {
    for(int j=1;j<=m;++j)
    {
      cin>>buffer;
      if(buffer=='#')
      {
        ++in[i];
        ++jn[j];
        if(in[i]>imn)
        {
          imn=in[i];
          im=i;
        }
        if(jn[j]>jmn)
        {
          jmn=jn[j];
          jm=j;
        }
      }
    }
  }
  cout<<im<<' '<<jm<<'\n';
}