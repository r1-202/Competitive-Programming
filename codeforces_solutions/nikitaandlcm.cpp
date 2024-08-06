#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int gcd(int a,int b)
{
    if(!a) return b;
    if(!b) return a;
    return gcd(b,a%b);
}

int get_lcm(int a, int b)
{
    int d = gcd(a,b);
    return (ll)(a)*(ll)(b)/(ll)(d);
}

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


void fill_divisors(int a, vector<int>& d)
{
    for(int i=1;i*i<=a;++i)
    {
        if(a%i==0)
        {
            d.push_back(i);
            if(a/i!=i) d.push_back(a/i);
        }
    }
}

void solve_case()
{
    int n;
    cin>>n;
    int a[2000];
    cin>>a[0];
    int m = a[0];
    for(int i=1;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>m) m=a[i];
    }
    bool multiple=true;
    for(int i=0;i<n;++i)
    {
        if(m%a[i]!=0)
        {
            multiple=false;
            break;
        }
    }
    if(!multiple)
    {
        cout<<n<<"\n";
        return;
    }

    vector<int> divisor;

    fill_divisors(m,divisor);
    int s=0;
    for(int d=0;d<divisor.size();++d)
    {
        int cs=0;
        int lcm = 1;
        for(int i=0;i<n;++i)
        {
            if(a[i]==divisor[d])
            {
                cs=0;
                break;
            }
            if(divisor[d]%a[i]!=0)
            {
                continue;
            }
            ++cs;
            lcm = (ll)lcm*(ll)a[i]/(ll)gcd(lcm,a[i]);
        }
        if(lcm==divisor[d])
            s=max(s,cs);
    }
    cout<<s<<"\n";
}