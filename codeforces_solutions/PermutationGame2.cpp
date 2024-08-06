#include <iostream>
#include <vector>
using namespace std;
long long getMaxScore(vector<int> p, vector<int> a, 
int n, int k, int initial_position);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,k,P_B,P_S;
    vector<int> p(2*100000);
    vector<int> a(2*100000);
    int i;
    long long m_B,m_S;


    cin>>t;
    for(int tt=0;tt<t;++tt)
    {
    cin>>n>>k>>P_B>>P_S;
    for(i=1;i<=n;++i)
    {
        cin>>p[i];
    }
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    long long x,y;
    x=y=0;
    m_S = m_B =0;
    for(int i=0;i<=min(n,k);i++)
    {
        m_B=max((long long)(k-i)*(long long)a[P_B]+x,m_B);
        m_S=max((long long)(k-i)*(long long)a[P_S]+y,m_S);
        x+=a[P_B],y+=a[P_S];
        P_B=p[P_B],P_S=p[P_S];
    }
    if(m_S>m_B)
        cout<<"Sasha"<<endl;
    else if(m_S<m_B)
        cout<<"Bodya"<<endl;
    else 
        cout<<"Draw"<<endl;
    }
    return 0;
}