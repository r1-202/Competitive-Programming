#include <iostream>
using namespace std;
void solve();   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t>0)
    {
        solve();
        --t;
    }

}
int n,k,q,d;
int i;
int low,high,m;
int a[100002];
int b[100002];
void solve()
{
    cin>>n>>k>>q;
    a[0]=0;
    for(i=1;i<=k;++i) cin>>a[i];
    b[0]=0;
    for(i=1;i<=k;++i) cin>>b[i];
    while(q>0)
    {
        cin>>d;
        //cout<<"\n";
        low = 0;
        high = k;
        while(high-low>1)
        {
            m = (high+low)/2;
            if(a[m]<d) low = m;
            else if(a[m]>d) high = m;
            else if(a[m]==d)
            {
                low = m;
                high = m+1;
            }
        }
        cout<<b[low]+(int64_t)(b[high]-b[low])*(d-a[low])/(a[high]-a[low])<<"\n";
        --q;
    }
    cout<<endl;
}