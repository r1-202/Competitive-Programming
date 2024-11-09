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
    cin>>t;
    while(t>0)
    {
        solve_case();
        --t;
    }
}

bool is_equal(char c1, char c2)
{
    if(c1=='?'||c2=='?') return true;
    return c1==c2;
}

void solve_case()
{
    string s;
    cin>>s;
    int m=s.size();
    if(m%2==1)--m;
    while(m>0)
    {
        int match_count=0;
        for(int j=0;j<m/2;++j)
        {
            if(is_equal(s[j],s[j+m/2]))
            {
                match_count++;
            }
        }
        if(match_count==m/2) break;
        bool b1=false;
        for(int i=1;i<=s.size()-m;++i)
        {
            if(is_equal(s[i-1],s[i-1+m/2])) --match_count;
            if(is_equal(s[i+m/2-1],s[i+m-1])) ++match_count;
            if(match_count==m/2)
            {
                b1=true;
                break;
            }
        }
        if(b1) break;
        m-=2;
    }
    cout<<m<<"\n";
}