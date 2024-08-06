#include <iostream>
using namespace std;
void solve_case();
int main()
{
  int t;
  cin>>t;
  while(t>0)
  {
    solve_case();
    --t;
  }
}
void solve_case()
{
    int n;
    int buffer;
    int a[101]={0};
    cin>>n;
    for(int i=1;i<=n;++i)
    {
      cin>>buffer;
      ++a[buffer];
    }
    buffer=0;
    for(int i=1;i<=100;++i)
    {
    if(a[i]>2)
     buffer+=a[i]/3;
    }
    cout<<buffer<<"\n"; 
}