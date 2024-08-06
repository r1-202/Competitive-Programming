#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve_case();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    cin>>n;
    vector<char> s(n);
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    int m=n;
    while(m>1)
    {
        bool works=true;
        int inversion_counter=0;
        queue<int> sub_inv;
        for(int i=0;i<n-m+1;++i)
        {
            if((!sub_inv.empty())&&i==sub_inv.front())
            {
                --inversion_counter;
                sub_inv.pop();
            }
            if((inversion_counter%2==0&&s[i]=='0')||(inversion_counter%2==1&&s[i]=='1'))
            {
                ++inversion_counter;
                sub_inv.push(i+m);
            }
        }
        for(int i=n-m+1;i<n;++i)
        {
            if((!sub_inv.empty())&&i==sub_inv.front())
            {
                --inversion_counter;
                sub_inv.pop();
            }
            if((inversion_counter%2==0&&s[i]=='0')||(inversion_counter%2==1&&s[i]=='1'))
            {
                works=false;
                break;
            }
        }
        if(works) break;
        --m;
    }
    cout<<m<<"\n";
}