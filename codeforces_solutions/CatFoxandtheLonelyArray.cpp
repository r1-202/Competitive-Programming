#include <iostream>
#include <fstream>
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
    int a[100001];
    int min = 1;
    int max = n;
    cin>>a[0];
    bool e = true;
    for(int i = 1;i<n;++i)
    {
        cin>>a[i];
        if(a[i]!=a[0]) e = false;
    }
    if(e)
    {
        cout<<"1\n";
        return;
    }
    while(max-min>1)
    {
        int k = (min+max)/2;
        int bits[21]={0};
        bool result = true;
        for(int i=0;i<k;++i)
        {
            int b = a[i];
            int j = 0;
            while(b>0)
            {
                if(b%2)
                {
                    ++bits[j];
                }
                b = b>>1;
                ++j;
            }
        }
        for(int i = 1;i<n-k+1;++i)
        {
            int b = a[i-1];
            bool ch[21]={false};
            int j = 0;
            while(b>0)
            {
                if(b%2)
                {
                    --bits[j];
                    if(bits[j]==0) ch[j]=true;
                }
                b = b>>1;
                ++j;
            }
            j = 0;
            b = a[i+k-1];
            while(b>0&&result)
            {
                if(b%2)
                {
                    if(bits[j]==0&&!ch[j])
                    {
                        result = false;
                        break;
                    }
                    ++bits[j];
                    ch[j]=false;
                }
                b = b>>1;
                ++j;
            }
            for(int i = 0;(i<21)&&result;++i)
            {
                if(ch[i]) result = false;
            }
            if(!result) break;
        }
        if(result)
        {
            max = k;
        }
        else
        {
            min = k;
        }
    }
    cout<<max<<"\n";
}